#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, K;
    cin >> N >> K;
    long double p[N];
    for (int i = 0; i < N; i++)
    {
        p[i] = 0.0;
        cin >> p[i];
    }
    
    long double ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans += ((p[i] + 1.0)/2.0);
    }
    
    long double temp = ans;
    for (int i = K; i < N; i++)
    {
        // temp -= ((p[i-K] + 1.0)/2.0);
        temp += ((p[i] - p[i-K])/2.0);
        ans = max(ans, temp);
    }
    cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
