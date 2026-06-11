
#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
//using namespace atcoder;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = numeric_limits<ll>::max();


#define debug(v) cout<<#v<<": ",prt(v);
template <typename A,typename B>
inline void prt(pair<A,B> p){cout<<"("<<p.first<<", "<<p.second<<")\n";}
template <typename A,typename B,typename C>
inline void prt(tuple<A,B,C> p){cout<<"("<<get<0>(p)<<", "<<get<1>(p)<<", "<<get<2>(p)<<")\n";}
inline void prt(bool p){if(p)cout<<"True"<<'\n';else cout<<"False"<<'\n';}
template <typename T> 
inline void prt(vector<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(deque<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(unordered_map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(set<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(multiset<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}

ll n,k;
ll p[3];//もらえるポイント
string t;

//r-0, s-1, p-2に対応

ll dp[200000][3];

bool win(int x,int y){
    if(t[x]=='r'&&y==2)return true;
    if(t[x]=='s'&&y==0)return true;
    if(t[x]=='p'&&y==1)return true;
    return false;
}

ll rec(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];
    if(x<k){
        if(win(x,y))return dp[x][y]=p[y];
        else return 0;
    }
    if(win(x,y)){
        ll res = 0;
        rep(i,3) {
            if(i==y)continue;
            chmax(res,rec(x-k,i));
        }
        return dp[x][y]=res+p[y];
    }
    else{
        ll res = 0;
        rep(i,3) {
            if(i==y)continue;
            chmax(res,rec(x-k,i));
        }
        return dp[x][y]=res;
    }
}


int main(){
    cin >> n >> k;
    cin >> p[0] >> p[1] >> p[2];
    cin >> t;
    ll ans = 0;
    rep(i,200000)rep(j,3)dp[i][j]=-1;
    for(int i=n-k;i<n;i++){
        ll tmp = 0;
        rep(j,3){
            chmax(tmp,rec(i,j));
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}

