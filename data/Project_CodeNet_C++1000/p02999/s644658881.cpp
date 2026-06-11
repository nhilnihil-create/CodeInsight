#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main(){
    int x,a; cin >> x >> a;
    if(x<a) cout << 0 << endl;
    else cout << 10 << endl;

    return 0;
}
