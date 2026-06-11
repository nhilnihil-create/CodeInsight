#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int n;cin>>n;
    int a[n],s[n+1];
    int sum=0;
    
    rep(i,n)cin>>a[i];
    s[0]=a[0];
    rep(i,n){
        sum+=a[i];
        s[i+1]=s[i]+a[i+1];
    }
    int ans = 99999999;
    rep(i,n){
        ans = min(ans,abs(s[i]-(sum-s[i])));
    }
    cout<<ans<<endl;
	return 0;
}