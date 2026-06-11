#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vec A(n),num(200001,0);
    rep(i,n) cin>>A[i],num[A[i]]++;
    ll ans=0;
    rep1(i,200000) ans+=num[i]*(num[i]-1)/2;
    rep(i,n){
        cout<<ans-(num[A[i]]-1)<<"\n";
    }
}