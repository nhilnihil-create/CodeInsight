#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
void mul(const char *a, const char *b);

int main() {
	char c[5], d[17];
	scanf("%s %s", d, c);
	for(int i = 1; i < 5; i++) {
		c[i] = c[i+1];
	}
	const char *p1 = d;
	const char *p2 = c;
	mul(p1, p2);
	return 0;
}

void mul(const char *a, const char *b) {
	int n1, n2;
	n1 = strlen(a);
	n2 = strlen(b);
	vector<int> s;
	for (int i = 0; i<n1 + n2; i++) {
		s.push_back(0);
	}	
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			s[i + j + 1] += (a[i] - '0') * (b[j] - '0');
		}
	}
	for (int i=n1+n2-1; i>=0; i--) {
		if (s[i] >= 10) {
			s[i-1] += s[i] / 10;
			s[i] %= 10;
		}
	}
	int i=0;
	while(s[i]==0) {
		i++;
	}
	if (i >= n1 + n2 - 2) {
		printf("0");
	} else {
		for (; i < n1 + n2 - 2; i++) {
			printf("%d", s[i]);
		}
	}
	printf("\n");
}