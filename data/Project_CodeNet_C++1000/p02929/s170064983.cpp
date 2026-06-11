#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < int > a(2 * n);
        for(int i = 0; i < 2 * n; i++){
                char c;
                cin >> c;
                a[i] = (c == 'B' ? 1 : 0);
                if(i % 2){
                        a[i] ^= 1;
                }
                if(a[i] == 0){
                        a[i] = -1;
                }
        }
        long long res = 1, bal = 0;
        for(int i = 0; i < 2 * n; i++){
                if(a[i] == -1){
                        res = res * bal % mod;
                }
                bal += a[i];
                if(bal < 0){
                        cout << 0 << "\n";
                        return 0;
                }
        }
        if(bal){
                cout << 0 << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                res = res * i % mod;
        }
        cout << res << "\n";
}
