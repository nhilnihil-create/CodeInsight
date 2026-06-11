#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {

    int n;
    cin >> n;
    vector<ll> acum(n);

    cin >> acum[0];
    fo(i, n - 1) {
        int a;
        cin >> a;
        acum[i + 1] = a + acum[i];
    }

    ll menor = INFLL;
    fo(i, n - 1) {
        menor = min(menor, abs(acum[i] - (acum[n - 1] - acum[i])));
    }

    cout << menor << endl;

    return 0;
}