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

vector<int> a(100002);

int main(){
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> c;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            c.push_back(0);
        } else {
            ll pos = 0;
            int tmp = -1;
            for(int j = 0; j < c.size(); j++){
                if(c[j] == a[i]-1){
                    tmp = j;
                    pos++;
                }
            }
            if(tmp == -1){
                cout << 0 << endl;
                return 0;
            }
            c[tmp]++;
            ans = ans*pos %MOD;
        }
    }

    for(ll j = 0; j < c.size(); j++){
        ans = ans * (3L-j) % MOD;
    }

    cout << ans << endl;
    return 0;
}