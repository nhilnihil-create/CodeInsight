
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

ll gcd(ll x, ll y){
    if(y==0) return x;
    else return gcd(y,x%y);
}

int main(){
    ll a, b;
    cin >> a >> b;
    int n = gcd(a,b);

    ll ans = a*b/n;
    cout << ans << endl;

}