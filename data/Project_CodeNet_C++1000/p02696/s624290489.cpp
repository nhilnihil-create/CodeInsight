#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    ll a,b,n,x,ans;
    cin>>a>>b>>n;
    ll m=n-(n%b)-1;
    ans=max(max(a*n/b-a*(n/b) , a*(n-1)/b-a*((n-1)/b)) , a*(m)/b-a*((m)/b));
    //ans=a*n/b-a*(n/b);
    cout<<ans<<endl;
}
