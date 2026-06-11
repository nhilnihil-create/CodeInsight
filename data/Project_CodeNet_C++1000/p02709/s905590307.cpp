#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<ll,int>> A;
    for (int i=0;i<N;++i){
        ll a; cin >> a;
        A.emplace_back(a,i);
    }
    sort(A.begin(),A.end()); reverse(A.begin(),A.end());
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,-IINF));
    dp[0][0]=0;
    for (int i=0;i<N;++i){
        for (int j=0;j<=N;++j){
            chmax(dp[i+1][j+1],dp[i][j]+A[i].first*abs(A[i].second-j));
            chmax(dp[i+1][j],dp[i][j]+A[i].first*abs(A[i].second-N+1+i-j));
        }
    }
    ll ans=0;
    for (int j=0;j<=N;++j) chmax(ans,dp[N][j]);
    cout << ans << '\n';
}