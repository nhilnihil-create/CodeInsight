#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll H; cin >> H;
    ll count=0;
    while(H!=1) {
        H/=2;
        count++;
    }
    ll ans = pow(2,count)*2-1;
    cout << ans << endl;
}