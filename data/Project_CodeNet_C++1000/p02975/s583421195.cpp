#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    ll N;
    ll i;
    ll A;
    map<ll, ll> count;
    cin >> N;
    rep(i, N){
        cin >> A;
        if (count.find(A) == count.end()) {
            count[A] = 1;
        } else {
            count[A]++;
        }
    }

    if (count.size() == 1 && count.find(0) != count.end()) {
        cout << "Yes\n";
    } else if (count.size() == 2){
        if (count.find(0) == count.end()) {
            cout << "No\n";
            return 0;
        } else {
            auto c = *count.upper_bound(0);
            if (count[0] * 2 == c.second){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            return 0;
        }
    } else if (count.size() == 3) {
        ll t = -1;
        ll xored = 0;
        for (auto p: count) {
            xored ^= p.first;
            if (t == -1){
                t = p.second;
            } else if (t != p.second) {
                cout << "No\n";
                return 0;
            }
        }
        cout << ((xored == 0) ? "Yes" : "No") << '\n';
    } else{
        cout << "No\n";
    }

    

    return 0;
}