#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void) {
    int n;
    cin >> n;
    vector<P> times;
    ll a, b;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        times.emplace_back(make_pair(b, a));
    }
    
    sort(times.begin(), times.end());
        
    ll cumsum = 0;
    bool flag = true;
    for (auto x : times) {
        cumsum += x.second;
        if (cumsum > x.first) {
            flag = false;
            break;
        }
    }
    
    cout << (flag ? "Yes" : "No") << endl;
    
    return 0;
}