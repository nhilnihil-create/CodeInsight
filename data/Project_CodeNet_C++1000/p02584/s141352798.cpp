#include <bits/stdc++.h>
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;

int dr[] = {0, 0, -1, +1, -1, -1, +1, +1};
int dc[] = {-1, +1, 0, 0, -1, +1, -1, +1};

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll moves = min(x/d, k);

    if((k-moves)&1) 
        cout << d - x%d << endl;
    else cout << x - moves * d << endl;
}

