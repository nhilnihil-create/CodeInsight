#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<vector>

using namespace std;


#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define ll long long
#define MOD 1000000007

#define IMIN INT_MIN;
#define IMAX INT_MAX;


int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll delta1, delta2;
    delta1 = t1*(a1-b1);
    delta2 = t2*(a2-b2);
    ll delta = delta1 + delta2;
    ll ans;

    if (delta == 0 || delta1 == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    // if no reverse in position can be achieved
    if ((delta1 > 0 && delta > 0) || (delta1 < 0 && delta < 0)) {
        cout << 0 << endl;
        return 0;
    }
    ans = 2 * (abs(delta1) / abs(delta)) + 1;
    if (delta1 % delta == 0) ans -= 1;
    cout << ans << endl;


	return 0;
}

