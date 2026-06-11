#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
long long k;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        long long res = 0, A = 0;
        for(int i = 1; i <= n; i++){
                long long B = 0;
                for(int j = i + 1; j <= n; j++){
                        A += (a[i] > a[j]);
                }
                for(int j = 1; j <= n; j++){
                        B += (a[i] > a[j]);
                }
                res = (res + B * (k * (k - 1) / 2 % mod)) % mod;
        }
        cout << (res + A * k) % mod << "\n";
}
