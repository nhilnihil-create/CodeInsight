#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],cnt[N],gd,ok;
signed main(){
	cin>>n; gd=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); gd=__gcd(gd,a[i]);
		for(int j=2;j*j<=a[i];j++) if(a[i]%j==0){
			while(a[i]%j==0) a[i]/=j;
			if(cnt[j]) ok=1;
			cnt[j]++;
		}
		if(a[i]>1){
			if(cnt[a[i]]) ok=1;
			cnt[a[i]]++;
		}
	}
	if(ok) puts(gd==1?"setwise coprime":"not coprime");
	else puts("pairwise coprime");
	return 0;
}
