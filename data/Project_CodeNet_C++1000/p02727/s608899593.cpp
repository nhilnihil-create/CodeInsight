#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int INF = (1LL<<31)-1;


int main(){
    ll x,y,a,b,c; cin >> x >> y >> a >> b >> c;
    priority_queue<ll> que0,que1,que2;
    rep(i,a){
        ll p; cin >> p;
        que0.push(p);
    }
    rep(i,b){
        ll q; cin >> q;
        que1.push(q);
    }
    rep(i,c){
        ll r; cin >> r;
        que2.push(r);
    }

    ll ans = 0;
    ll X=x,Y=y;
    rep(i,X+Y){
        ll p=0,q=0,r=0;
        ll ma = 0;

        if(!que0.empty() && a>0 && x>0){
            p=que0.top();
        }
        if(!que1.empty() && b>0 && y>0){
            q=que1.top();
        }
        if(!que2.empty() && c>0){
            r=que2.top();
        }
        ma = max(p,q); ma = max(ma,r);
        ans+=ma;

        if(ma == p){
            a--;
            x--;
            que0.pop();
            continue;
        }
        if(ma == q){
            b--;
            y--;
            que1.pop();
            continue;
        }
        if(ma == r){
            c--;
            que2.pop();
            continue;
        }
    }

    cout << ans << endl;
}