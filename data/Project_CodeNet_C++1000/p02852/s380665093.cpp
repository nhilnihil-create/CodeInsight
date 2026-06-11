#include<bits/stdc++.h>
using namespace std;

#define ran 101101

int n, k;
char s[ran];
int ans[ran], la;

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	
	la = 0;
	int it = n, cnt = 0;
	while(it>0) {
		int last = it;
		it=max(0, it-k);
		while(s[it]=='1') it++;
		if(it>=last) {
			puts("-1");
			return 0;
		}
		ans[la++] = last - it;
	}
	for(int i=la-1;i>=0;i--)
		printf("%d%c", ans[i], i>0 ? ' ' : '\n');
	
	return 0;
}
