#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int L, R;
    cin >> L >> R;

    int ans = 2018;
    if (R - L >= 2019)
    {
        for (int i = L; i < L + 2019; i++)
        {
            for (int j = i + 1; j <= L + 2019; j++)
            {
                ans = min(ans, ((i % 2019) * (j % 2019)) % 2019);
            }
            
        }
        
    } else
    {
        for (int i = L; i < R; i++)
        {
            for (int j = i + 1; j <= R; j++)
            {
                ans = min(ans, ((i % 2019) * (j % 2019)) % 2019);
            }
            
        }
    }
    
    cout << ans << endl;

  return 0;
}
