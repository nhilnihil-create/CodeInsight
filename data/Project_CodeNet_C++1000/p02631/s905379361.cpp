#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int mod = 1e9+7;
const ll INF = 1e18;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> v(N);
    ll ans = 0;
    for(auto &i : v){
        cin >> i;
        ans ^= i;
    }
    string sol = "";
    for(int i = 0 ; i < N ; i++){
        ans ^= v[i];
        sol += (to_string(ans) + " ");
        ans ^= v[i];
    }
     
    cout << sol;
}
