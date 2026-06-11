#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    string S;
    cin >> S;
    int N = (int)S.size();
    vll cnt(N+1);
    for(int i=0; i<N; i++){
        if(S[i] == '<'){
            chmax(cnt[i+1],cnt[i]+1LL);
        }
    }
    for(int i=N-1; i>=0; i--){
        if(S[i] == '>'){
            chmax(cnt[i],cnt[i+1]+1LL);
        }
    }
    ll ans = 0;
    for(auto c:cnt){
        ans += c;
    }
    cout << ans << endl;
}