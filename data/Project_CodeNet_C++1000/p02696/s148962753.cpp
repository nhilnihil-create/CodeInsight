#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll a,b,n;
    cin >> a >> b >> n;
    ll x;
    if(n>=b-1) x = b-1;
    else x = n;
    ll ans = (a*x)/b - a*(x/b);
    cout << ans << endl;
}
    


