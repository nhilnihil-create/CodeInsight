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


int main() {

    int n;
    cin >> n;
    vi h(n);

    fo(i, n) cin >> h[i];

    int cont = 0;
    int ans = 0;
    for ( int i = n - 2; i >= 0; i-- ) {
        if ( h[i] >= h[i + 1] ) {
            cont++;
            ans = max(ans, cont);
        } else {
            cont = 0;
        }
    }

    cout << ans << endl;

    return 0;
}