#include<bits/stdc++.h>
using namespace std;

char s[110];
int n;

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(n & 1) return puts("No"), 0;
	for(int i = 2; i <= n; i += 2)
		if(s[i] != 'i' || s[i - 1] != 'h') return puts("No"), 0;
	puts("Yes");
	return 0;
}