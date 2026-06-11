/*
Problem : https://atcoder.jp/contests/abc145/tasks/abc145_f
Algorithm : dp
Status :
*/
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 1e18;
const int MAXN = 305;

int n,k;
ll a[MAXN],f[MAXN][MAXN];

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		f[i][0] = 0;
		f[i][1] = a[i];
	}
	for(int j = 2;j <= n - k;j++){
		for(int i = j;i <= n;i++){
			for(int l = 1;l <= i - 1;l++)
			    f[i][j] = min(f[i][j],f[l][j - 1] + max(0ll,a[i] - a[l]));
		}
	}
	ll ans = INF;
	for(int i = 1;i <= n;i++)
	    ans = min(ans,f[i][n - k]);
	printf("%lld\n",ans);
	return 0;
}
