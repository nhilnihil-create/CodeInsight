#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INFINITO 1000000000
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

const int INF = 1E9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {

    ll n, a, b;
    cin >> n >> a >> b;

    ll dist = abs(a - b);
    if ( dist == 1 ) {
        cout << min(max(n - a, n - b), max(a - 1, b - 1)) << endl;
    } else if ( dist & 1 ) {
        ll menor = INFLL;
        ll aux;

        aux = min(n - a, n - b) + 1 + (dist - 1) / 2;
        menor = min(aux, menor);
        aux = min(a - 1, b - 1) + 1 + (dist - 1) / 2;
        menor = min(aux, menor);

        cout << menor << endl;
    }else {
        cout << abs(a - b) / 2 << endl;
    }

    return 0;
}