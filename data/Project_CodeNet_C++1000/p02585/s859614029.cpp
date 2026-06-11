#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;
 
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n+10,0),c(n+10,0);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
 
    ll ans = -1e10;
    for(int i = 1; i <= n; i++){
        ll sum = 0,ti = p[i],j = 1;
        while(i != ti) { ti = p[ti]; j++; }
        if(k < j){
            for(int l = 1; l <= k; l++){
                sum += c[p[ti]];
                ans = max(ans,sum);
                ti = p[ti];
            }
        }else{
            for(int l = 1; l <= j; l++){
                sum += c[p[ti]];
                ans = max(ans,sum);
                ti = p[ti];
            }
            if(sum >= 0){
                sum = (k/j-1)*sum;
                for(int l = 1; l <= j+k%j; l++){
                    sum += c[p[ti]];
                    ans = max(ans,sum);
                    ti = p[ti];
                }
            }
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
 
	return 0;
}