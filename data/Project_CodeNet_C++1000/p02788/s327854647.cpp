#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
    ll n,d,a; cin >> n >> d >> a;
    vector<P> mon(n);
    rep(i,n) cin >> mon[i].first >> mon[i].second;
    sort(all(mon));

    ll sbt=0;
    ll ans=0;
    queue<P> rv;
    rep(i,n){
        for(;;){
            if(rv.empty()) break;
            else{
                if(rv.front().first<mon[i].first){
                    sbt-=rv.front().second;
                    rv.pop();
                }
                else break;
            }
        }
        ll times=((mon[i].second-sbt-1)/a)+1;
        if(mon[i].second-sbt>0){
            ans+=times;
            rv.push(P(mon[i].first+2*d,times*a));
            sbt+=times*a;
        }
    }
    
    cout << ans << endl;
return 0;
}


