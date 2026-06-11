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
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    int n, d;

    cin >> n >> d;
    int x[10][10];

    fo(i, n) {
        fo(j, d) cin >> x[i][j];
    }

    int ans = 0;
    fo(i, n - 1) {
        for ( int j = i + 1; j < n; j++ ) {
            int cont = 0;
            fo(k, d) cont += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            // cout << cont << endl;
            if ( sqrt(cont) == floor(sqrt(cont)) ) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}