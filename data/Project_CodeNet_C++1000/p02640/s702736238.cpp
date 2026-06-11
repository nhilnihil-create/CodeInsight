#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    bool ok = false;
    for (int i = 0; i <= x; ++i) {
        if(i * 2 + (x-i) * 4 == y){
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";

    return 0;
}
