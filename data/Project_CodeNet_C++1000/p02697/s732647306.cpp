#include<bits/stdc++.h>
using namespace std;



int main()
{
int n, m;


	scanf("%d%d", &n, &m);
	if(n & 1); else n--;
	int l = 1, r = (n + 1) / 2 + 1;
	int t = n / 2;
	for(int i = 1; i <= m; i++) {
		if(i & 1) {
			printf("%d %d\n", l, l + t);
			t--;
			l++;
		}
		else {
			printf("%d %d\n", r, r + t);
			t--;
			r++;
		}
	}
}