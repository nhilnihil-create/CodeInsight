#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

ll mulfi(ll n){
    ll cnt = 0;
    while(n > 0){
        cnt += n / 5;
        n /= 5;
    }   

    return cnt;
}


int main(){

    ll n;
    cin >> n;

    ll cnt = 0;

    if(n % 2 != 0){
        cout << 0 << endl;
        return 0;
    }

    cnt = mulfi(n/2);

    cout << cnt << endl;

}