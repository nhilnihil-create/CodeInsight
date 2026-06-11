#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
      if (i % 3 == 0 || i % 5 == 0)
        continue;
      else
        cnt += i;
    }
    cout << cnt << endl;
    return 0;
}