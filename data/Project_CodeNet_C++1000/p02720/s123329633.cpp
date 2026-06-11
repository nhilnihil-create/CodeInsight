#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i,n) for (int i = 0; i < (n); ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main(){
    ll k;
    cin >> k;
    queue <ll> q;
    FOR(i,1,10) q.push((ll)i); // 1~9
    ll cnt = 0;
    while(1){
        ll x = q.front();
        // 終了判定
        cnt++;
        if(cnt==k){
            cout << x << "\n";
            return 0;
        }
        // push
        if(x%10 != 0) q.push(10*x + (x%10) -1);
        q.push(10*x + (x%10));
        if(x%10 != 9) q.push(10*x + (x%10) +1);
        // pop
        q.pop();
    }
    
    return 0;
}