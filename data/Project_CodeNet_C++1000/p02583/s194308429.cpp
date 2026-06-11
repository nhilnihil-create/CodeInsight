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
    int n;
    ll ans=0;
    cin>>n;
    vec L(n);
    rep(i,n) cin>>L[i];
    rep(i,n)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){
        vec A(3);
        A[0]=L[i],A[1]=L[j],A[2]=L[k];
        sort(all(A));
        if(A[0]==A[1]||A[1]==A[2]) continue;
        if(A[0]+A[1]>A[2]) ans++;
    }
    cout<<ans;
}