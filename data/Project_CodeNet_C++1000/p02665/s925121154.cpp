#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//print(fixed << setprecision(10));
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repk(i,n,k) for(int i = k; i < (n); i++)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl
double PI = acos(-1.0);
int INF = 1e9;
ll LINF = 1e18;
ll MOD = 1e9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll sum=0;
    vector<ll> a(n+1);
    rep(i,n+1){
        cin >> a[i];
        sum += a[i];
    }

    ll root = 1;
    ll mp = 1;
    ll ans = 0;
    rep(d,n+1){
        sum -= a[d];
        if(a[d] > mp){
            ans = -1;
            break;
        }
        if(d==0) if(a[d]>0 && n>0){
            ans = -1;
            break;
        }
        if(d==n){
            if(a[d]<root || a[d]>root*2) ans = -1;
            else ans += a[d];
        }
        else{
            if(a[d] > root*2){
                ans = -1;
                break;
            }
            if(d!=0) root = min(mp-a[d], min(sum,root*2-a[d]));
            if(root<1){
                ans = -1;
                break;
            }
            ans += root + a[d];
        }
        mp = min(mp*2,100000000+sum);
    }
    print(ans);
    return 0;
}