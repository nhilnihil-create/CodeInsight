#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
long long s[N];
long long b[N];
long long a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 0; i <= n; i++){
                cin >> b[i];
        }
        for(int i = n; i >= 0; i--){
                s[i] = s[i + 1] + b[i];
        }
        a[0] = 1;
        long long res = 0;
        for(int i = 0; i <= n; i++){
                a[i] = min(a[i], s[i]);
                if(b[i] > a[i]){
                        cout << -1 << "\n";
                        return 0;
                }
                a[i + 1] = (a[i] - b[i]) * 2;
                res += a[i];
        }
        cout << res << "\n";
}
