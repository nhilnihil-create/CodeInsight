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
ll dp[3001][3001][4],A[3001][3001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin>>n;
    int a=0;
    rep(i,n.size()) (a+=(n[i]-'0'))%=9;
    if(a==0) cout<<"Yes";
    else cout<<"No";
}