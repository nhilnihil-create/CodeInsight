#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x,n;
    cin >> x >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int c=1;
    int ans=0;
    while(true) {
        if(n==0) {
            ans = x;
            break;
        }
        if (count(p.begin(), p.end(), x) == 0){
            ans = x;
            break;
        }
        if (count(p.begin(), p.end(), x-c) == 0) {
            ans = x-c;
            break;
        } else if(count(p.begin(), p.end(), x+c) == 0) {
            ans = x+c;
            break;
        }
        ++c;
    }
    cout << ans << endl;
    return 0;
}