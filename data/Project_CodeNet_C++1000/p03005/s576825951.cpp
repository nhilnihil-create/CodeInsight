#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    if (K==1) {
        cout << 0 << "\n";
        return 0;
    }else{
        cout << N - K << "\n";
        return 0;
    }
}