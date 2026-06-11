#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};
ll N,M;
vector<ll> a(1005);
//vector<vector<bool>> c2(1005,vector<bool>(12)); 
vector<ll> c(1005);
//vector<vector<ll>> dp(1005,vector<ll>(5000,-1));

vector<ll> dp(5000,-1);

ll ans = -1;
ll rec(ll bit,ll v){
    //cout<<bitset<12>(bit)<<endl;
    if(dp[bit] != -1){
        return dp[bit];
    }

    if(bit == (ll(1)<<N)-1){
        //cout << "OK"<< endl;
        return dp[bit] = 0;
    }

    ll res = INF;
    rep(i,M){
        if(bit != (bit|c[i])){
            chmin(res,rec(bit | c[i],i)+a[i]);
        }
    }
    return dp[bit] = res;
}
int main() {
    
    cin >>N>>M;
    

    rep(i,M){
        ll b;
        cin>>a[i]>>b;
        rep(j,b){
            ll C;
            cin>>C;
            //c2[i][C-1]=1;
            c[i] |= ll(1)<<(C-1);

        }
    }
    
    rec(0,-1);
    ans = dp[0];
    if(ans == INF){
        ans=-1;
    }
    cout << ans << endl;
    
    


    return 0;
    

}