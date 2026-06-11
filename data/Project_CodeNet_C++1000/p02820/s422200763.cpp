#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    int n, k;  cin >> n >> k;
    ll r, s, p; cin >> r >> s >> p;
    string c;   cin >> c;
    
    vector<int> f;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i-k >= 0 && c[i] == c[i-k]) {
            auto ite = lower_bound(f.begin(), f.end(), i-k);
            if (ite != f.end() && *ite == i-k) {
                if (c[i] == 'r')
                    ans += p;
                else if (c[i] == 's')
                    ans += r;
                else 
                    ans += s;
            }
            else 
                f.push_back(i);
        }
        else {
            if (c[i] == 'r')
                    ans += p;
                else if (c[i] == 's')
                    ans += r;
                else 
                    ans += s;
        }
    }

    cout << ans << endl;
    return 0;
}