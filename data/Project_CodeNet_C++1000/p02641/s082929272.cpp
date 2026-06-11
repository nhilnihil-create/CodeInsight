#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll X, N;
    cin >> X >> N;
    vector<ll> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i];
    ll res = 100000;
    ll out = 0;
    for (int i = 0; i < 105; ++i) {
      if (p.end() != find(p.begin(), p.end(), i)) continue;
      else{
        if(abs(X-i)<res){
            res = abs(X-i);
            out = i;
        }
      }
    }
    cout << out << endl;
    return 0;
}