#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


int main(){
    string n;
    cin >> n;
    n.insert(0, 1, '0');
 
    vector<array<ll, 2>> dp(n.size());
    dp.at(0).at(0) = n.at(0) - '0';
    dp.at(0).at(1) = 1 + (n.at(0) - '0');
    for(ll i = 1; i < n.size(); ++i){
        const ll d = n.at(i) - '0';
        dp.at(i).at(0) = min(
            dp.at(i - 1).at(0) + d,
            dp.at(i - 1).at(1) + 10 - d
        );
        dp.at(i).at(1) = min(
            dp.at(i - 1).at(0) + d + 1,
            dp.at(i - 1).at(1) + 9 - d
        );
    }
    cout << dp.at(n.size() - 1).at(0) << endl;
    return 0;
}
