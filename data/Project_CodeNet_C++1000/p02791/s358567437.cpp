#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
    int n;
    cin >> n;
    
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    
    int mn = 0, ans = 0;
    
    rep(i,n) {
        if(i == 0 || p.at(i) < mn) {
            ans++;
            mn = p.at(i);
        }
    }
    cout << ans << endl;
}