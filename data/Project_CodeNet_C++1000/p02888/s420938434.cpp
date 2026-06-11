#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[2050];
void solve(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			int k=lower_bound(a+j+1,a+n+1,a[i]+a[j])-a;
			ans+=(k-j-1);
		}
	}
	printf("%d",ans);
}

signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}