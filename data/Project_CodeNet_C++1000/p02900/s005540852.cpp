#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    ll ans = x / gcd(x, y) * y;
    return ans;
}

int main(){
    ll a,b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    vector<ll> l;
    for(ll i = 1; i*i <= a; i++){
        if(a%i == 0){
            if(b%i == 0) l.push_back(i);
            ll t = a/i;
            if(t != i && b%t == 0) l.push_back(t);
        }
        if(b%i == 0){
            ll t = b/i;
            if(t != i && a%t == 0) l.push_back(t);
        }
    }
    sort(l.begin(), l.end());
    
    ll ans = 0;
    for(int i = 0; i < l.size(); i++){
        if(l[i] == -1) continue;
        ans++;
        if(l[i] == 1) continue;
        for(int j = i+1; j < l.size(); j++){
            if(l[j] == -1) continue;
            if(l[j]%l[i] == 0){
                l[j] = -1;
                continue;
            }
            for(ll k = 2; k*k <= l[i]; k++){
                if(l[i]%k == 0 && l[j]%k == 0){
                    l[j] = -1;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}