#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;

int main(){
    ll n,a,b,ans=0;
    cin>>n>>a>>b;
    ans+=n/(a+b)*a;
    n=n%(a+b);
    if(n<=a) ans+=n;
    else ans+=a;
    cout<<ans;
}