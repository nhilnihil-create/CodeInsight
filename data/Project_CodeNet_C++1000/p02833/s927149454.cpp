#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define int long long

using namespace std;
const int inf = 1e18;
const double EPS = 0.00000001;
const int mod = 1000000007;

signed main(){
    int n;
    cin >> n;
    if(n&1){
        cout << 0;
        return 0;
    }
    int c = 0;
    int x = 10;
    int cc = 1;
    while(1){
        if(n/x == 0) break;
        c += cc*n/x;
        x *= 5;
    }
    cout << c;
}
