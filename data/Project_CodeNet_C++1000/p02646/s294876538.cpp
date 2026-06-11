#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.in", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);

#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX int(50000)+10

const int INF = 0x3f3f3f3f;
using namespace std;

int main() {

    IO

    ll a, v, b, w, k, x, y;
    cin >> a >> v >> b >> w >> k;
    x = abs(a - b), y = (v - w) * k;
    cout << (x <= y ? "YES\n" : "NO\n");

    return 0;
}