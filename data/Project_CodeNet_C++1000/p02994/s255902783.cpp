#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, L;
    cin >> N >> L;

    int skip;
    if (L < 1)
    {
        skip = min(N, 1 - L);
    } else
    {
        skip = 1;
    }
    
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == skip)
        {
            continue;
        }
        ans += L + i - 1;
    }
    cout << ans << endl;
  return 0;
}
