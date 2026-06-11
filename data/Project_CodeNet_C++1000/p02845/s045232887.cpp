#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e+9 + 7;

int main(){
    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ans = ans * ((a == x) + (a == y) + (a == z)) % mod;
        if(x == a){
            x++;
        } else if(y == a){
            y++;
        } else {
            z++;
        }
    }
    cout << ans << endl;
    return 0;
}