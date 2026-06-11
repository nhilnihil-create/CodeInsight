#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll L, R;
    cin >> L >> R;
    vector<ll> V;

    for(ll i=L; i<=R; i++) {
        V.push_back(i % 2019);
        if(i % 2019 == 0 && i!= 0) break;
    }
    ll min_value = 2020;
    for(int i=0; i<V.size(); i++) {
        for(int j=i+1; j<V.size(); j++) {
            min_value = min((V[i] * V[j]) % 2019, min_value);
        }
    }
    cout << min_value << endl;
}