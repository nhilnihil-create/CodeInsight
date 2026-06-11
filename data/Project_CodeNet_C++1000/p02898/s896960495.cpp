#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define int long long

using namespace std;
const int inf = 1e18;
const double EPS = 0.00000001;
const int mod = 1000000007;

signed main(){
    int n,a;
    cin >> n >> a;
    int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        if(x >= a) cnt++;
    }
    cout << cnt;
}
