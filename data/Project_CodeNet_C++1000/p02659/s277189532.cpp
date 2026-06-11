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
    ll a;
    double b;
    cin >> a >> b;
    ll ib = b*100+0.1;
    ll ans = (a*ib)/100;
    cout << ans << endl;
}