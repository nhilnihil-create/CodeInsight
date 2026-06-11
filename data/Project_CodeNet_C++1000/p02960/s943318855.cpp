#include <bits/stdc++.h>

using namespace std;
#define N 100100
#define MOD 1000000007LL

long long d[13][N];
string s;
int n, i, j, k, digit;
int main()
{
    cin >> s;
    n = s.size();
    for (i = 0; i < 13; ++i) d[i][0] = 0;
    d[0][0] = 1;
    for (i = 0; i < n; ++i){
        if (s[i] != '?'){
            for (j = 0; j < 13; ++j)
                d[(j * 10 + s[i] - '0') % 13][i + 1] = d[j][i];
        }
        else{
                for (digit = 0; digit < 10; ++digit){
                for (j = 0; j < 13; ++j){
                    k = (j * 10 + digit) % 13;
                    d[k][i + 1] += d[j][i];
                    if (d[k][i + 1] > MOD)
                        d[k][i + 1] -= MOD;
                }
            }
        }
    }
    cout << d[5][n];
    return 0;
}
