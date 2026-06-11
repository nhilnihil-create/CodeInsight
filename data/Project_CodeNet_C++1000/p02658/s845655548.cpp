#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T&a , T b){ if(a<b){ a=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&a , T b){ if(a>b){ a=b; return true; } else{ return false; } } 

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n){
        if(a[i]==0){
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    rep(i,n){

        if(a[i]<=10e18/ans){
            ans *= a[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(ans>(ll)10e17){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}