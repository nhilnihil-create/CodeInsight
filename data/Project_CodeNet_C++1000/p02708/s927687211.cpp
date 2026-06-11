#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll N,K;
    cin >> N >> K;

    ll sum = 0;
    for(int p = K; p <= N + 1; p++){
      ll tmp = (N - p + 1) * p + 1;
      tmp = tmp % MOD;
      sum = (sum + tmp) % MOD;
    }
    cout << sum << endl;
}
