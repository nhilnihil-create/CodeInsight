#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      total += A[i];
    }
      ll cnt = 0;
      for (int i = 0; i < N; i++) {
        if (A[i] * 4 * M < total) continue;
        else
          cnt++;
      }
    if(cnt>=M)cout << "Yes" << endl;
    else cout <<"No" << endl;
    return 0;
}