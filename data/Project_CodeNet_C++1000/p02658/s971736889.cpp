#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    ll zero = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] == 0) zero++;
    }
    if(zero>0) {
      cout << 0 << endl;
      return 0;
    }
    ll out = 1;
    for (int i = 0; i < N; i++) {
        if(out>1000000000000000000/A[i]){
            cout << -1 << endl;
            return 0;
        } else {
          out *= A[i];
        }
    }
    cout << out << endl;
    return 0;
}