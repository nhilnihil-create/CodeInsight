#include <bits/stdc++.h>

#define FILE
#define fr first
#define se second

using namespace std;

const long long N = 2e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

int k;
int q;
long long d[N];
int main()
{
    #ifdef FILEs
        freopen("input.txt", "r", stdin);
        /// freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    cin >> k >> q;
    for(int i = 1; i <= k; i ++){
        cin >> d[i];
    }
    while(q --){
        long long n, x, m;
        cin >> n >> x >> m;
        x %= m;
        long long s = 0;
        long long res = n - 1;
        for(int i = 1; i <= k; i ++){
            int q = (n - 1 - i + k) / k;
            s += (q * (d[i] % m));
            if(d[i] % m == 0){
                res -= q;
            }
        }
        long long last = x + s;
        res -= last / m;
        cout << res << "\n";
    }
}

