#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define mod 1000000007

int main() {
	int n;

    cin >> n;
    int a[15];
    int x[15][15]; int y[15][15];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            if ((bit >> i) & 1){
                for (int j = 0; j < a[i]; j++)
                {
                    if (((bit >> (x[i][j] - 1)) & 1) ^ y[i][j]) ok = 0;
                }
            }
        }
        if (ok) {
            int count = 0;
            rep(i, n) {
                if ((bit >> i) & 1)count++;
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
	return 0;
}