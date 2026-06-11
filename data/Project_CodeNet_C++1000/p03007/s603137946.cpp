#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t



int main(){
    ll N; cin >> N;
    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    ll SUM = V[N-1], idx = N-1;
    for(int i = 0; i < N-1; i++) SUM-=V[i];
    ll ans = SUM;
    for(int i = N-2; i > 0; i--){
        SUM += 2*V[i];
        if(ans < SUM){
            ans = SUM;
            idx = i;
        }
    }
    cout << ans << endl;
    vector<ll> A;
    ll idx2 = idx-1;
    ll t = V[idx2];
    idx2--;
    while(idx < N-1){
        cout << t << " " << V[idx] << endl;; 
        t -= V[idx];
        idx++;
    }
    A.push_back(t);
    while(idx2 >= 0){
        A.push_back(V[idx2]);
        idx2--;
    }
    t = V[N-1];
    for(auto a : A){
        cout << t << " " << a << endl;
        t -= a;
    }


}