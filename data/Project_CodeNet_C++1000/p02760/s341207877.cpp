#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    vector<vector<ll>> a(3,vector<ll>(3));
    rep(i,3){
        rep(j,3){
            cin>>a[i][j];
        }
    }
    ll n;cin>>n;
    
    rep(i,n){
        ll b;cin>>b;
        rep(j,3){
            rep(l,3){
                if(a[j][l]==b) a[j][l]=-1;
            }
        }
    }

    bool check=false;
    rep(i,3){
        bool hai=true;
        rep(j,2){
            if(a[i][j]!=a[i][j+1]) hai=false;
        }
        if(hai==true){
            check=true;
            break;
        }
    }

    rep(i,3){
        bool hai=true;
        rep(j,2){
            if(a[j][i]!=a[j+1][i]) hai=false;
        }
        if(hai==true){
            check=true;
            break;
        }
    }

    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
        check=true;
    }
    if(a[0][2]==a[2][0] && a[1][1]==a[0][2]){
        check=true;
    }

    if(check) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}