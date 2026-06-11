#include <bits/stdc++.h>
using namespace std;

#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
    }

    bool ans = true;
    if(m.size() > 3){
        cout << "No" << endl;
        return 0;
    }
    if(m.size() == 3){
        ll x = 0;
        for(auto p : m){
            x ^= p.first;
            if(p.second * 3 != n) ans = false;
        }
        if(x != 0) ans = false;
        ans ? cout << "Yes" << endl : cout << "No" << endl;
        return 0;
    }
    if(m.size() == 2){
        bool z = false;
        for(auto p : m){
            if(p.first == 0){
                z = true;
                if(p.second * 3 != n) ans = false;
            }else{
                if(p.second * 3 != 2 * n) ans = false;
            }
        }
        if(!z) ans = false;
        ans ? cout << "Yes" << endl : cout << "No" << endl;
        return 0;
    }

    for(auto p : m){
        if(p.first != 0) ans = false;
    }
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}
