#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, cnt, sum=0;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> ball;
    rep1(i, n){
        cin >> a[i];
        ball[a[i]]++;
    }
    for (auto& i : ball){
        cnt = i.second;
        sum += cnt * (cnt-1) / 2;
    }
    ll ans = 0; 
    rep1(i, n){
        cnt = ball[a[i]];
        ans = sum - (cnt - 1);
        cout << ans << endl;
    }
}