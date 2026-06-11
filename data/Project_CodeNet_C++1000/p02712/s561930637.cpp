#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    vector<long long > a(n);
    rep(i,n) a.at(i) = i+1;
    rep(i,n){
        if(a.at(i) % 3 == 0|| a.at(i) % 5 == 0){
            continue;
        }
        else ans+=i+1;
    }
    cout << ans << endl;

}
