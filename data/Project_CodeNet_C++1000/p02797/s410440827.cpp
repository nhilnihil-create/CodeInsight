#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k,s;
    cin >> n >> k >> s;

    if (s == 1e9){
        for (ll i = 0; i < k; i++){
            cout << s << " ";
        }
        for (ll i = k; i < n; i++){
            cout << s-1 << " ";
        }
        cout << endl;
    }
    else{
        for (ll i = 0; i < k; i++){
            cout << s << " ";
        }
        for (ll i = k; i < n; i++){
            cout << s+1 << " ";
        }
        cout << endl;
    }

}