#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll N;
vector<ll> H;

int main() { 
    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    ll out = 0, tmp=0;
    for (int i = 0; i<N; i++){
      if(i==N-1){
        out = max(out, tmp);
      } else if (H[i + 1] <= H[i]) {
        tmp++;
      } else {
        out = max(out, tmp);
        tmp = 0;
      }
    }
    cout << out << endl;
    return 0;
}