#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main() {
    
    ll A,B;
    cin >> A >> B;

    ll ans;
    ll c = gcd(A,B);
    ans = A / c * B;

    cout << ans << endl;

}