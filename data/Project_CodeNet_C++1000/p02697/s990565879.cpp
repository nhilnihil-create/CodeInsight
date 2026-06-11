#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int n,m;
    cin>>n>>m;
    if(n%2) rep(i,m) cout<<i+1<<" "<<n-i<<"\n";
    else{
        rep(i,min(m,n/4)) cout<<i+1<<" "<<n/4*2-i<<"\n";
        rep(i,max(0,m-n/4)) cout<<n/4*2+2+i<<" "<<n-i<<"\n";
    }
}