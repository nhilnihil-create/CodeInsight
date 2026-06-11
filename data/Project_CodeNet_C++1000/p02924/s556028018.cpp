#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ;
    cin >> n;
    int ans = n * (n - 1);
    ans >>= 1;
    cout << ans << endl;

    return 0;
}
