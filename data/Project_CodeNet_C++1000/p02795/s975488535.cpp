#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
        #include "debug.h"
        #define input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        #else
        #define debug(...) 4
        #define input ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int main() {
    input;
        
    int n, m, k;
    cin >> n >> m >> k;
    cout << (k + max(n, m) - 1) / max(n, m);
    
}   