#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

int a[N];
int b[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    for(int i = 0 ; i < n ; ++i)    cin >> a[i];
    for(int i = 0 ; i < n ; ++i)    cin >> b[i];

    ll  ans = 0;

    while (1)   {
        bool ok = 1;

        for(int i = 0 ; i < n ; ++i)    {
            if (b[i] < a[i])    {
                cout << "-1";
                return  0;
            }
            if (b[i] > a[i])    {
                int j = (i - 1 + n) % n;
                int k = (i + 1) % n;

                if (b[i] <= b[j] || b[i] <= b[k])   {
                    ok = 0;
                    continue;
                }
                if (b[i] - a[i] < b[j] + b[k])  {
                    cout << "-1";
                    return  0;
                }
                int cnt = (b[i] - a[i]) / (b[j] + b[k]);
                ans  += cnt;
                b[i] -= cnt * (b[j] + b[k]);

                if (b[i] != a[i])
                    ok = 0;
            }
        }
        if (ok) {
            cout << ans;
            return  0;
        }
    }
}
