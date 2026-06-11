#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> X;

int main(){
    cin >>N;
    X.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    ll out = 99999999;
    for (int i = 1; i <= 100; i++){
      ll tmp = 0;
      for (int j = 0; j < N; j++) {
        tmp += (X[j] - i)*(X[j]-i);
      }
      out = min(tmp, out);
    }
    cout << out << endl;
    return 0;
}