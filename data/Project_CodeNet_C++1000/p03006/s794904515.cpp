#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    int N; cin >> N;
    vector<pair<ll, ll>> V(N);
    for(int i = 0; i < N; i++){
        ll x, y; cin >> x >> y;
        V[i] = make_pair(x, y); 
    } 
    sort(V.begin(), V.end());
    map<pair<ll, ll>, int> M;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            M[make_pair(V[j].first - V[i].first, V[j].second - V[i].second)]++;
        }
    }
    ll Max = 0;
    for(auto m : M) Max = max(Max, (ll)m.second);
    cout << N - Max << endl;

}