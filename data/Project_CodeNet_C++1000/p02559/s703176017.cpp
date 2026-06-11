#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
    ll n,q,a;
    cin>>n>>q;
    fenwick_tree<ll> A(n);
    rep(i,n) cin>>a,A.add(i,a);
    rep(i,q){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0) A.add(b,c);
        else cout<<A.sum(b,c)<<"\n";
    }
}