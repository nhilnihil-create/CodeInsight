// 物极必反

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 5e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9;
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

    long long n, k; cin >> n >> k;

    vector<long long> a(n + 2);
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }

    while(k--){
        bool flag = false;
        vector<long long> d(n + 2);
        for(long long i = 1; i <= n; i++){
            long long l = max(i - a[i], 1ll), r = min(i + a[i], n);
            d[l]++, d[r + 1]--;
        }
        for(long long i = 1; i <= n; i++){
            d[i] += d[i - 1];
            if(d[i] != a[i]) flag = true;
        }
        a = d;
        if(!flag) break;
    }

    for(long long i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
