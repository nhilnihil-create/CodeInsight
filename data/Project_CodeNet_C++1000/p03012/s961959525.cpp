#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    int W[N];
    for(int i = 0; i < N; i++){
        W[i] = 0;
        cin >> W[i];
        sum += W[i];
    }

    int ans = sum;
    int S1 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        S1 += W[i];
        ans = min(ans, abs(sum - S1 - S1));
    }
    cout << ans << endl;

  return 0;
}
