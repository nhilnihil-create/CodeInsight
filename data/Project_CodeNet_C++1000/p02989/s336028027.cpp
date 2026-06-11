// 物极必反

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 5e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 998244353;
const long long INF = 1e18 + 9;
const int SM = 3e3 + 5;
const int logN = 22, BL = 400;
const long double EPS = 1e-14;
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug(){
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

int main(){
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n; cin >> n;

    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << a[n / 2] - a[n / 2 - 1];

    return 0;
}
