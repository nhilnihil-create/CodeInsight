#include <bits/stdc++.h>

#define ll long long
#define N (ll)(4*1e6)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;

const ll maxN = 2010;
 
ll pascal[maxN][maxN];

void monta() {
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(ll i = 2; i < maxN; i++) {
        pascal[i][0] = 1;
        for(ll j = 1; j < maxN; j++) {
            pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1])%M;
        }
    }
}

int main() {
    // 189 algorithm design manual
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    monta();
    
    ll n, k;

    cin >> n >> k;

    ll b = k;
    ll r = n - k;

    for(ll i = 1; i <= k; i++) {
        ll quantidades = (pascal[r+1][i]%M)*(pascal[b-1][i-1]%M)%M;
        cout << quantidades << endl;
    }
 

    return 0;
}