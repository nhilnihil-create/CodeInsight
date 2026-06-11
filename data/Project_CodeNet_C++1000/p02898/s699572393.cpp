#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (h[i] < K)
        {
            break;
        }
        ans++;
    }
    cout << ans << endl;
  return 0;
}
