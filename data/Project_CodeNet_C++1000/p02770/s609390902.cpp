#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
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
    ll k,q;
    cin>>k>>q;
    vec A(k);
    rep(i,k) cin>>A[i];
    rep(i,q){
        ll n,x,m,sum=0,count=0;
        cin>>n>>x>>m;
        vec B(k);
        rep(i,k) B[i]=A[i]%m,sum+=B[i];
        rep(i,k) if(B[i]==0) count++;
        n--;
        sum=sum*(n/k);
        count=count*(n/k);
        sum+=x%m;
        rep(i,n%k) sum+=B[i];
        rep(i,n%k) if(B[i]==0) count++;
        cout<<n-count-sum/m<<"\n";
    }
}