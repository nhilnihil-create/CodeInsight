#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;
#define N 22369620
#define X 50
struct hush
{
	list <int> a;
};
int main(void)
{
	int n, sum = 0, x, f[1000000] = { 0 }, cou = 0;
	char str[7], acgt[13];
	hush H[N / X];
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) {
		sum = 0;
		scanf("%s", str);
		scanf("%s", acgt);
		for (int i = 0, k = 1; acgt[i] != '\0' &&i < 12; i++, k *= 4) {
			switch (acgt[i]) {
			case 'A': x = 1; break;
			case 'C': x = 2; break;
			case 'G': x = 3; break;
			case 'T': x = 4; break;
			}
			sum += x*k;
		}
		if (str[0] == 'i') {
			H[sum / X].a.push_back(sum % X);
		}
		else {
			list<int>::iterator p = H[sum / X].a.begin();
			for (; p != H[sum / X].a.end(); ++p) {
				if ((sum % X) == *p) { f[cou] = 1; }
			}
			cou++;
		}
	}
	for (int i = 0; i < cou; i++) {
		if(f[i]) printf("yes\n");
		else printf("no\n");
	}
}