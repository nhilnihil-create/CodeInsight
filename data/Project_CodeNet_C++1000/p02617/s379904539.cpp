#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll ret = 0;
    for(ll i = 1 ; i <= N ; ++i){
        ret += i * (N+1-i);
    }
    for(ll i = 0; i < N-1 ; ++i){
        ll u, v;
        cin >> u >> v;
        ret -= (min(u, v) * (N+1 - max(u, v)));
    }
    cout << ret << endl;

    return 0;


}