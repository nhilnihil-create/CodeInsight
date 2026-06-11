//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 5e5 + 5;
const int M = 17 + 5;
const int W = 1000 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int n,a[N],b[N],cnt;

void init() {
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b,b+n);

    for (int i = 0; i < n; ++i) {
        if(a[i]!=b[i]) ++cnt;
    }

    cout << (cnt>2 ? "NO" : "YES") << '\n';

    return 0;
}