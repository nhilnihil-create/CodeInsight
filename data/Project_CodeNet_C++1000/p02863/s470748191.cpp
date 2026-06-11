#include <bits/stdc++.h>
#define pii pair<int, int>
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int maxn = 3*(1e3) + 100;
const ll oo = 1e9 + 100;

int memo[3100][3100];
pii a[3100];

int knap(int v, int bag){
    if (v < 0 || bag <= 0) return 0;
    if (memo[v][bag] != -1) return memo[v][bag];
    return memo[v][bag] = max(knap(v-1, bag), knap(v-1, bag-a[v].ff) + a[v].ss);
}


int main(void){
    int n, t;
    cin >> n >> t;
    memset(memo, -1, sizeof memo);

    for (int i=0; i<n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a, a+n);
    reverse(a, a+n);
    

    cout << knap(n-1, t) << endl;
return 0;
}