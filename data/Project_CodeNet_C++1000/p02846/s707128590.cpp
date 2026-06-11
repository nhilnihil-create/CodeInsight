#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int t1,t2; cin >> t1 >> t2;
    ll a1,a2,b1,b2; cin >> a1 >> a2 >> b1 >> b2;
    if(a1*t1+a2*t2 == b1*t1+b2*t2) cout << "infinity" << endl;
    else{
        if(a1 < b1){
            swap(a1,b1);
            swap(a2,b2);
        }
        if(a1*t1+a2*t2 > b1*t1+b2*t2) cout << 0 << endl;
        else{
            ll s = (b1-a1)*t1;
            ll t = (a1-b1)*t1+(a2-b2)*t2;
            ll k = s/t+1;
            ll ans = 2*k-1;
            if(s%t == 0) ans--;
            cout << ans << endl;
        }
    }
    
}
