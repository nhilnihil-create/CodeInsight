#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define R(a) a=sqrt(a)
#define POW(a,b) a=pow(a,b)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    FAST;
    ll n,P,Q;
    ll ans=0;
    cin>>n;
    ll p[n];
    ll q[n];
    ll l=1;
    string s[2];
    rep(i,n){
        cin>>p[n];
        s[0]+=p[n];
    }
    rep(i,n){
        cin>>q[n];
        s[1]+=q[n];
    }
    sort(s,s+2);
    while(s[0]<s[1]){
        next_permutation(s[0].begin(),s[0].end());
        ans++;
    }


    cout<<ans;
    
}

