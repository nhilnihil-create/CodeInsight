#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<ll> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll res = n;
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            ll sub = 0;
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(k == l)continue;
                    if(dx == x[l] - x[k] && dy == y[l] - y[k])sub++;
                }
            }
            res = min(res,n - sub);
        }
    }
    cout << res << endl;
}