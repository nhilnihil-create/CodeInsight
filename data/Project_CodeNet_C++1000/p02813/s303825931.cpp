#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    vector<ll> P(N), Q(N), V(N); 
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> Q[i];
    for(int i = 0; i < N; i++) V[i] = i+1;

    ll cnt = 0, cnt1, cnt2;
    do{
        bool f1 = true, f2 = true;
        for(int i = 0; i < N; i++) if(V[i] != P[i]) f1=false;
        for(int i = 0; i < N; i++) if(V[i] != Q[i]) f2=false;
        if(f1) cnt1 = cnt;
        if(f2) cnt2 = cnt;
        cnt++;

    }while(next_permutation(V.begin(), V.end()));
    cout << abs(cnt2-cnt1) << endl;

} 
