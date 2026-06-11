#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    ll cnt = 0;
    for (int i = 0; i < M; i++) cnt += A[i];
    if(cnt<=N) cout << N-cnt << endl;
    else cout << -1 << endl;
    return 0;
}