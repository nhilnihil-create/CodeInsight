#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define inf 1e18
#define mod 1e9+7
#define w(x) int x; cin >> x; while(x--)
#define sp(x, y) fixed << setprecision(y) << x;
#define pb push_back


const int maxn = 1e6;
const ll mx = 1e18;

ll n;
void solve() {
    cin >> n;
    cout << (n * (n - 1)) / 2;
}

int main() {

    solve();
    return 0;
}

