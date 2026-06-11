#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >>N;
    vector<ll> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    ll cnt = 0;
    ll minj = P[0];
    for (int i = 0; i < N; ++i) {
      minj = min(minj, P[i]);
      if (P[i] <= minj) cnt++;
    }
    cout << cnt << endl;
    return 0;
}