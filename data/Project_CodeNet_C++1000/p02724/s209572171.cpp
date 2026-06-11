#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll X; cin >> X;
    ll happy_500 = X/500;
    ll happy_5 = (X%500)/5;
    ll ans = 1000*happy_500 + 5*happy_5;
    cout << ans << endl;
    return 0;
}