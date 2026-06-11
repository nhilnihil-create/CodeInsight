#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    ll S;
    cin >> S;
    ll ret1 = (S + 1000000000 - 1) / 1000000000;
    ll ret2 = ret1 * 1000000000 - S;
    cout << 0 << " " << 0 << " " << 1 << " " << 1000000000 << " " << ret1 << " " << ret2 << endl;
}