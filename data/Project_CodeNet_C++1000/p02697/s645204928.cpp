#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e16;




int main(){
    int n,m;
    cin >> n >> m;
    if(n%2==1){
        rep(i,min(m,n/2)){
            cout << i+1 << ' ' << n-i-1 << endl;
        }
    }
    else{
        rep(i,min(m,n/4)){
            cout << i+1 << ' ' << n-i << endl;
        }
        rep(i,(m-n/4)){
            cout << i+n/4+1 << ' ' << n-n/4-i-1 << endl;
        }
    }
    return 0;
}
