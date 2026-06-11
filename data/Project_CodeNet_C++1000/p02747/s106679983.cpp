#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cctype>
#define LL long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 3;
char s[N];
int n; 
int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	if(n & 1){
		puts("No");
		return 0;	
	}
	bool flag = 1;
	for(int i = 1;i <= n;i += 2) if(s[i] != 'h') flag = 0;
	for(int i = 2;i <= n;i += 2) if(s[i] != 'i') flag = 0;
	puts(flag ? "Yes" : "No");
	return 0;
}

