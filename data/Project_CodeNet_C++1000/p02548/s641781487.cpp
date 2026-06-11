#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1e9+7
#define INF 1 << 30
#define MAX (1 << 20)
#define NINF (-(1 << 30))
#define Point pair<int, int>
#define triplet pair<pair<int, int>, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    ll ans = 0;

    for (int c = 1; c < n; c++) {
        int num = n - c;

        int lim = sqrt(num);

        for(int i = 1; i <= lim; i++) {
            if(!(num%i)) {
                if(i != (num/i))
                    ans += 2;
                else
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}