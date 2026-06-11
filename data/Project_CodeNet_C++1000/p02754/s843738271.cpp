
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(n % (a+b) == 0){
        cout << (n/(a+b))*a << endl;
        return 0;
    }
    else{
        ll ans = (n/(a+b))*a;
        if(n%(a+b) <= a){
            ans += n%(a+b);
            cout << ans << endl;
            return 0;
        }
        else{
            ans += a;
            cout << ans << endl;
            return 0;
        }
    }
}