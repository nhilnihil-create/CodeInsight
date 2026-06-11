#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(a) a.begin(), a.end()

const int maxn = 100010;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;
int n, m, a[maxn];
string s, ss;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, t;
    cin >> n >> x >> t;
    cout << ((n+x-1)/x)*t;
}