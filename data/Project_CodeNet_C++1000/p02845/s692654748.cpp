#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int x, y, z; x = y = z = 0;
    ll ans = 1;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        if(a==x && a==y && a==z){
            x++;
            ans = ans * 3 % mod;
        } else if(a==x && a==y){
            x++;
            ans = ans * 2 % mod;
        } else if(a==x){
            x++;
        } else if(a==y && a==z){
            y++;
            ans = ans * 2 % mod;
        } else if(a==y){
            y++;
        } else if(a==z){
            z++;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}