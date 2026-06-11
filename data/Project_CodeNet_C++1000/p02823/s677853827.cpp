#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if((b-a)%2 == 0){
        cout << (b-a)/2 << endl;
    }else{
        ll m = min(a + b - 2, 2 * n - a - b);
        cout << (m + 1) / 2 << endl;
    }
    
}