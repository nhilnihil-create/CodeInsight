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


int main(){
    ll n,d,a;
    cin >> n >> d >> a;
    map<ll,ll> mon;
    for(int i = 0; i < n; i++){
        ll x,h;
        cin >> x >> h;
        mon[x] = h;
    }

    ll ans = 0;
    auto it = mon.begin();
    ll attack = 0;
    queue<pair<ll,ll>> cnt;
    while(it != mon.end()){
        while(cnt.size() != 0){
            auto rng = cnt.front();
            if(rng.first <= it->first){
                attack -= rng.second;
                cnt.pop();
            } else {
                break;
            }
        }

        ll hp = it->second - attack*a;

        if(hp > 0){
            ll num = hp/a;
            if(hp%a) num++;
            cnt.push({it->first+d*2L+1L,num});
            attack += num;
            ans += num;
        }
        it++;
    }

    cout << ans << endl;

    return 0;
}