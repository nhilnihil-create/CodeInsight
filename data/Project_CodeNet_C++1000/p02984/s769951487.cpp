#include<iostream>
#define ll long long
using namespace std;

ll a[200050],ans[200050];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i%2==1)ans[1]+=a[i];
		else ans[1]-=a[i];
	}
	for(int i=2;i<=n;i++){
		ans[i]=-ans[i-1]+2*a[i-1];
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
}

signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}