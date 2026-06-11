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

    int A, B, M;
    cin >> A >> B >> M;
    int menor = INFINITO, menora = INFINITO, menorb = INFINITO;
    vi a(A), b(B);
    fo(i, A) {
        cin >> a[i];
        menora = min(menora, a[i]);
    }
    fo(i, B) {
        cin >> b[i];
        menorb = min(menorb, b[i]);
    }

    fo(i, M) {
        int x, y, c;
        cin >> x >> y >> c;
        menor = min(menor, a[x - 1] + b[y - 1] - c);
    }

    cout << min(menor, menora + menorb) << endl;

    return 0;
}