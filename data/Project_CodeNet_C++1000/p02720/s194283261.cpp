#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


vll v;
ll lim=3234566667;

void make(ll i){
    queue<ll> que;
    que.push(i);
    while(!que.empty()){
        ll A=que.front();
        v.pb(A);
        ll a=A%10;
        que.pop();
        if(a==0){
            ll b=A*10+0;
            ll c=A*10+1;
            if(b<=lim) que.push(b);
            if(c<=lim) que.push(c);
        }
        else if(a==9){
            ll b=A*10+8;
            ll c=A*10+9;
            if(b<=lim) que.push(b);
            if(c<=lim) que.push(c);
        }
        else{
            ll b=A*10+a-1;
            ll c=A*10+a;
            ll d=A*10+a+1;
            if(b<=lim) que.push(b);
            if(c<=lim) que.push(c);
            if(d<=lim) que.push(d);
        }
    }

}




void solve() {
    
    ll k;
    cin>>k;
    rep2(i,1,10){
        make(i);
    }
    sort(v.begin(),v.end());
    cout<<v[k-1]<<endl;
    



}





signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    solve(); 


    return 0;
}
