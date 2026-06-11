#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//input
ll h,w;
vector<string>s;

ll l[2020][2020];
ll r[2020][2020];
ll u[2020][2020];
ll d[2020][2020];


int main(){
    cin >> h >> w;
    s.resize(h+1);
    rep(i,h){
        cin>>s[i];
    }
    for(int i=1;i<=h;i++){//left
        for(int j=1;j<=w;j++){
            if(s[i-1][j-1]=='#')l[i][j]=0;
            else {
                l[i][j]=l[i][j-1]+1;
            }
        }
    }
    for(int i=1;i<=h;i++){//right
        for(int j=w;j>=1;j--){
            if(s[i-1][j-1]=='#')r[i][j]=0;
            else r[i][j]=r[i][j+1]+1;
        }
    }
    for(int i=1;i<=h;i++){//up
        for(int j=1;j<=w;j++){
            if(s[i-1][j-1]=='#')u[i][j]=0;
            else {
                u[i][j]=u[i-1][j]+1;
            }
        }
    }
    for(int i=h;i>=1;i--){//down
        for(int j=w;j>=1;j--){
            if(s[i-1][j-1]=='#')d[i][j]=0;
            else d[i][j]=d[i+1][j]+1;
        }
    }
    ll ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(s[i-1][j-1]=='#')continue;
            chmax(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
        }
    }
    cout << ans << endl;


    return 0;
}