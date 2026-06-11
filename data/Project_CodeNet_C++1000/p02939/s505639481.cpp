
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
const ll INF = 1e18;


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

string s;

ll dp[200020][2];

int main(){
    cin >> s;
    dp[0][0]=1;
    dp[1][1]=1;
    dp[0][1]=-INF;
    ll n = s.size();
    for(int i=1;i<n;i++){
        chmax(dp[i][0],dp[i-1][1]+1);
        if(s[i]!=s[i-1]){
            chmax(dp[i][0],dp[i-1][0]+1);
            chmax(dp[i][0],dp[i-1][1]+1);
        }
        if(i==1)continue;
        chmax(dp[i][1],dp[i-2][0]+1);
        if(i-3<0)continue;
        if(s.substr(i-3,2)!=s.substr(i-1,2)){
            chmax(dp[i][1],dp[i-2][0]+1);
            chmax(dp[i][1],dp[i-2][1]+1);
        }
    }
    cout << max(dp[n-1][1],dp[n-1][0]) << endl;
    return 0;
}

