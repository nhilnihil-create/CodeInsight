#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//入力
ll n;

int ans[510][510];

void solve(int l,int r,int level){
    if(l+1==r)return;
    int c = (l+r)/2;
    for(int i=l;i<c;i++){
        for(int j=c;j<r;j++){
            ans[i][j]=level;
        }
    }
    solve(l,c,level+1);
    solve(c,r,level+1);
    return;
}

int main(){
    cin >> n;
    solve(0,n,1);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            cout<<ans[i][j] << ' ';
        }
        cout<< ans[i][n-1] << endl;
    }

    return 0;
}