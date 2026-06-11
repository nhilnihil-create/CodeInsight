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
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n&1){
        int ans = b[n/2]-a[n/2]+1;
        cout << ans << endl;
    }
    else{
        int now1 = b[n/2]+b[n/2-1];
        int now2 = a[n/2]+a[n/2-1];
        int ans = now1-now2+1;
        cout << ans << endl;

    }
}

