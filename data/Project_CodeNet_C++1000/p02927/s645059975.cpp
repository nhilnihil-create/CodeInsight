#include<bits/stdc++.h>
using namespace std;
#define N 5000
typedef long long LL;
int m, d;

int main() {
    //freopen("sample.in", "r", stdin);
    cin >> m >> d;
    int ans = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= d; j++)
            if ((j % 10 >= 2) && (j / 10 % 10 >= 2) && (i == (j % 10) * (j / 10 % 10))) {
                //cout << i << " " << j << endl;
                ans++;
            }
    cout << ans << endl;
}