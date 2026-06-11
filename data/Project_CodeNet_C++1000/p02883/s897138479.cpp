#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, k ;
    cin >> n >> k;
    ll a[n], f[n];
    for(int i=0;i<n;i++){
    	cin >> a[i];
    }
    for(int i=0;i<n;i++){
    	cin >> f[i];
    }
    sort(a,a+n);
    sort(f,f+n);
    reverse(f, f+n);
    ll le = -1LL, ri = INF, mid;
    while(ri - le > 1LL){
    	mid = (ri + le) / 2LL;
    	ll num = 0;
    	for(int i=0;i<n;i++){
    		num += max(0LL, a[i] - mid / f[i]);
    		/*if(mid % f[i] == 0LL){
    			num += max(0LL, a[i] - mid / f[i]);
    		}else{
    			num += max(0LL, a[i] - (mid / f[i]) - 1LL);
    		}*/
    	}
    	if(num <= k) ri = mid;
    	else le = mid;
    }
    cout << ri << endl;
    return 0;
}
