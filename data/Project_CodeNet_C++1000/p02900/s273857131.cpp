#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll x,y; cin>>x>>y;
map <ll,ll> d;
for (long long a = 2; a * a <= x; ++a) {
        if (x % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (x % a == 0) {
            ++ex;
            x /= a;
        }

        d[a]++;
    }
    if (x != 1) d[x]=1;
for (long long a = 2; a * a <= y; ++a) {
        if (y % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (y % a == 0) {
            ++ex;
            y /= a;
        }
        d[a]++;
    }
    if (y != 1) d[y]++;
ll ca = 0;
for(auto p : d){
   //cout << p.fi << " " << p.se << endl;
   if(p.se==2){
   ca++;}
}
cout << ca+1 << endl;}
