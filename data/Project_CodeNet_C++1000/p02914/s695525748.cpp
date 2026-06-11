#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }

    ll s = 0;
    for(int i = 0; i < n; ++i){
        s ^= a.at(i);
    }

    for(int j = 0; j < n; ++j){
        a.at(j) &= ~s;
    }

    int r = 0;
    for(int k = 60; k >= 0; --k){
        bool found = false;
        for(int i = r; i < n; ++i){
            if((a.at(i) >> k) & 1){
                swap(a.at(r), a.at(i));
                found = true;
                break;
            }
        }
        if(!found){
            continue;
        }
        for(int i = 0; i < n; ++i){
            if(i == r){ continue; }
            if((a.at(i) >> k) & 1){
                a.at(i) ^= a.at(r);
            }
        }
        r++;
    }

    ll s2 = 0;
    for(int i = 0; i < n; ++i){
        s2 ^= a.at(i);
    }

    ll ans = s + 2 * s2;
    cout << ans << endl;
    return 0;
}