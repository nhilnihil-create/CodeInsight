#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;


int main(){
    ll N; cin >> N;
    unordered_map<ll, bool> M, taboo;

    vector<ll> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
        if(!M[V[i]])M[V[i]] = true;
        else taboo[V[i]] = true;
    }
    ll cnt = 0;
    for(int i = 0; i < N; i++){
        ll x = V[i];
        if(taboo[x]) continue;
        bool flag = true;
        for(int j = 1; j * j <= x; j++){
            if(x % j == 0){
                int k = x/j;
                //cout << x << " " << j << " " << k << endl;

                if((j != x && M[j] == true) || (k != x && M[k] == true)) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cnt++;
    }
    cout << cnt << endl;

}
