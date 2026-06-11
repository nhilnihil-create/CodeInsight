#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    vector<ll> s(n, 0);
    REP(i, n){
        ll ai;
        cin >> ai;
        s.at(--ai)++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;
    REP(i, n){
        if(s.at(i)){
            que.push(s.at(i));
        }
    }
    vector<ll> ans(n, 0);
    for(ll i = que.size(); i >= 1; --i){
        ans.at(i - 1) = que.top();
        if(que.size() > 1){
            ll x1 = que.top(); que.pop();
            for(; x1 > 0; --x1){
                ll x2 = que.top(); que.pop();
                que.push(x2 + 1);
            }
        }
    }
    REP(i, ans.size()){
        cout << ans.at(i) << endl;
    }
    return 0;
}
