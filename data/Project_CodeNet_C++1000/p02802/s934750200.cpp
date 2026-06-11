#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;
int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> p(M);
    vector<string> S(M);
    for (ll i=0; i<M; i++) {
        cin >> p[i] >> S[i];
    }
    vector<vector<ll>> kaitou(N,vector<ll>(2,0));
    ll countAC = 0;
    ll countWA = 0;
    for (ll i=0; i<M; i++) {
        if (S[i] == "AC") {
            if (kaitou.at(p[i]-1).at(0) == 0) {
                kaitou.at(p[i]-1).at(0) = 1;
            }
        }
        else if (kaitou.at(p[i]-1).at(0) == 0){
            kaitou.at(p[i]-1).at(1)++;
        }
    }
    for (ll i=0; i<N; i++) {
        countAC += kaitou.at(i).at(0);
        if (kaitou.at(i).at(0) == 1) {
            countWA += kaitou.at(i).at(1);
        }
    }
    cout << countAC << " " << countWA << endl;
}