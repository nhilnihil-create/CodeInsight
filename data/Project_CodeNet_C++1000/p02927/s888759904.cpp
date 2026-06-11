#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n, m;
        cin >> n >> m;
        int res = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 10; j <= m; j++){
                        if(j / 10 > 1 && j % 10 > 1 && (j / 10) * (j % 10) == i){
                                res += 1;
                        }
                }
        }
        cout << res << "\n";
}
