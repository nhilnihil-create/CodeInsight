#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    long long n,m;
    cin >> n >> m;
    vector<long long> a(m);
    rep(i,m) cin >> a.at(i);
    rep(i,m){
        n -= a.at(i);
        if(n < 0){
            n = -1;
            break;
        }
    }
    cout << n << endl;

}
