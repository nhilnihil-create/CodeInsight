#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll ans;
    if(n<b){
        ans = (a*n/b)-a*(n/b);
    }else{
        n=b-1;
        ans = (a*n/b)-a*(n/b);
    }
    cout<<ans<<endl;
}