#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    ll ans_a = max((ll)0,a-k);
    k = max((ll)0,k-a);
    ll ans_b = max((ll)0,b-k);
    cout << ans_a << " " << ans_b << endl;
}