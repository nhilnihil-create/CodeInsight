#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力

vector<vector<ll> > G;
vector<bool> seen;
vector<ll> h;

ll cnt=1;
ll mx;
ll flag;
//ll fcnt=1;
void dfs(ll v){
    seen[v] = 1;
    if(h[v]==mx){
        flag = 1;
    }
    if(h[v]>mx){
        mx = h[v];
        flag = 0;
    }
    rep(i,G[v].size()){
        if(seen[G[v][i]] == 0){
            dfs(G[v][i]);
        }
    }

}

int main() {
    ll n,m;
    cin >> n>>m;
    G.resize(n);
    seen.resize(n);
    h.resize(n);

    rep(i,n){
        cin>>h[i];
    }

    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    ll ans  = 0;
    vector<ll> an(n);
    rep(k,n){
        
        if(an[k]==0){

            for(ll i : G[k]){
                if(h[k]==h[i]){
                    an[k] = 1;
                    an[i] = 1;
                    break;
                } else if(h[k] < h[i]){
                    an[k] = 1;
                    break;
                }else{
                    an[i] = 1;
                }
            }
 
            
        }
    }

    rep(i,n){
        if(an[i]==0){
            ans++;
        }
    }
    cout <<ans<<endl;

    
   
    


    return 0;
    

}