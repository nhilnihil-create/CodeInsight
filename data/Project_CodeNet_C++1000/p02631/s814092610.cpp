#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    ll XOR = 0;
    for(int i = 0; i < N; i++) XOR = XOR ^ A[i];
    for(int i = 0; i < N; i++) cout << (XOR^A[i]) << " ";
    cout << endl;
}