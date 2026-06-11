#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];} 
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";} cout<<endl;
#define S second
#define F first
#define SZ(x) (int)x.size()
typedef long long ll;
typedef long double ld;
const int  MOD = 1e9 + 7;
const int  N = 1e6 + 7;
const int  M = 1e4 ;

void solve(){
    ll n , d , a;
    cin>>n>>d>>a;
    vector<pair < ll , ll > > v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i].F>>v[i].S;
    }
    sort(v.begin(), v.end());
    queue< pair< ll , ll > > q;
    ll sum = 0;
    ll res = 0;
    for(int i = 0 ; i < n; i++){
        while(q.size() > 0 && q.front().F < v[i].F){
            sum -= q.front().S;
            q.pop();
        }
        v[i].S -= a * sum;
        if(v[i].S <= 0) continue;

        ll tmp = (v[i].S + a - 1) / a;
        res += tmp;
        q.push({v[i].F + 2 * d, tmp});
        sum += tmp;
    }
    cout<<res<<endl;
}	
 
int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) solve();
    return 0;
}