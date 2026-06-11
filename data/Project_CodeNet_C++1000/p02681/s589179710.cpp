//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1000 + 5;
const int M = 201;
const int Q = 2e5 + 5;
const int OO = 2e9;
const int mod = 998244353;

string a,b;

void init() {
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    bool ok = 1;

    for (int i = 0; i < a.size(); ++i) {
        if(a[i]!=b[i]) ok = 0;
    }

    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}
