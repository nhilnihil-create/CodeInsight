#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    ll diff = (V - W);
    if(abs(A-B) <= diff*T){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
