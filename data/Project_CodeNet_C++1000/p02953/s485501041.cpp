#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h.at(i);
    int max = 0;
    rep(i, n-1){
        if(max < h.at(i)) max = h.at(i);
        if(max > h.at(i+1) + 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}