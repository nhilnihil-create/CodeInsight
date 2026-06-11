#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; i++) {
      cin >> H[i];
    }
    for (int i = 1; i < N; i++) {
      if (H[i - 1] > H[i]) {
        cout << "No\n";
        return 0;
      } else {
        if (H[i] != H[i - 1]) {
          H[i] = H[i] - 1;
        }
      }
    }
    cout << "Yes\n";
    return 0;
    
    
}

