#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const ll powll = 1LL<<1;

int main(){
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        int a[n];
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        int ans = MOD;
        rep(i,0,n-1){
            ans = min(ans, abs(a[i]-a[i+1]));
        }
        cout << ans << "\n";
    }
	
}
