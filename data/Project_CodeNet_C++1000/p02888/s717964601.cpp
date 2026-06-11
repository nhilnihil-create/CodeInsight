#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    rep(i,n-2) {
        int pos = i+2;
        for(int j = i+1; j < n-1; j++) {
            if(pos == j) pos++;
            while(l[pos] < l[i]+l[j] && pos < n) {
                pos++;
            }
            pos--;
            if(pos == j) {
                pos++;
                continue;
            }
            ans += pos - j;
        }
    }
    cout << ans << endl;

    return 0;
}
