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
    ll n;
    cin >> n;
    ll ans = 0;

    if(n%2 == 0){
        ll tmp = n;
        ll cnt = 0;
        while(tmp >= 10){
            cnt++;
            tmp /= 10;
        }
        ll div = 1;
        ll div_f = 50;
        for(int i = 1; i <= cnt; i++){
            div *= 10;
            ans += n/div;
            while(div % div_f == 0){
                ans += n/div_f - n/div;
                div_f *= 5;
            }
        }
        while(n >= div_f){
            ans += n/div_f;
            div_f *= 5;
        }

    }

    cout << ans << endl;

    return 0;
}