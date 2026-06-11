#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

int main(){
    ll n; cin >> n;
    vl a(n);
    ll mcnt = 0;
    ll pcnt = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i] <= 0) mcnt++;
        if(a[i] >= 0) pcnt++;
    }
    sort(all(a));
    vpl ans;
    if(mcnt == n){
        for(ll i=n-2; i>=0; i--){
            ans.emplace_back(a[n-1],a[i]);
            a[n-1] -= a[i];
        }
    }else if(pcnt == n){
        REP(i,1,n-1){
            ans.emplace_back(a[0],a[i]);
            a[0] -= a[i];
        }
        ans.emplace_back(a[n-1],a[0]);
        a[n-1] -= a[0];
    }else{
        ll index;
        rep(i,n){
            if(a[i] >= 0){
                index = i;
                break;
            }
        }
        if(index == n-1){
            rep(i,n-1){
                ans.emplace_back(a[n-1],a[i]);
                a[n-1] -= a[i];
            }
        }else{
            REP(i,index+1,n-1){
                ans.emplace_back(a[0],a[i]);
                a[0] -= a[i];
            }
            if(a[index] >= 0){
                ans.emplace_back(a[0],a[index]);
                a[0] -= a[index];
                rep(i,index){
                    ans.emplace_back(a[n-1],a[i]);
                    a[n-1] -= a[i];
                }
            }else{
                rep(i,index+1){
                ans.emplace_back(a[n-1],a[i]);
                a[n-1] -= a[i];
                }
            }
        }
    }
    cout << a[n-1] << endl;
    rep(i,n-1) cout << ans[i].first << " " << ans[i].second << endl;
}