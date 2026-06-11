#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll pow(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    ll d = pow(a, b / 2);
    return (d * d) % MOD;
  } else {
    ll d = pow(a, b - 1);
    return (a * d) % MOD;
  }
}

vector<ll> a(100001);

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }

    if(a[0] == 1){
        if(n == 0){
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    ll ans = 0;
    vector<ll> pos(n+1,0);
    ll calc = 1;
    for(int i = 0; i <= n; i++){
        if(a[i] > calc || (i!=0 && (pos[i-1]*2 < a[i] || pos[i-1] == 0))){
            cout << -1 << endl;
            return 0;
        } else {
            if(i!=0){
                if(pos[i-1]-a[i] < INF/2){
                    pos[i] = pos[i-1]*2-a[i];
                } else {
                    pos[i] = pos[i-1]-a[i];
                }
                ans += a[i];
            } else {
                pos[i] = 1;
            }
        }
        if(calc < INF/2){
            calc *= 2;
        }
    }

    pos[n] = a[n];
    for(int i = n-1; i >= 0; i--){
        pos[i] = min(pos[i+1],pos[i]);
        ans += pos[i];
        pos[i] += a[i];
    }

    cout << ans << endl;

    return 0;
}