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
        
    int n, k, s;
    cin >> n >> k >> s;
    int a[n];

    for(int i = 0; i < n; i++) {
        if(s != 1e9)
            a[i] = s + 1;
        else
            a[i] = 1;

    }
    for(int i = 0; i < n; i++)
        cout << (i < k ? s : a[i]) << " ";
    

}   