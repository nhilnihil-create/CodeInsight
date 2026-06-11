#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
#define rep(i, n)  for (int i = 0; i <  (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ll INF = ll(1e18)+1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll l,r,d;
    ll result=0;
    cin >> l >> r >> d;

    rep(i,r-l+1){
        // cout << i+l << "\n";
        if((i+l) % d == 0) result++;
    }

    cout << result;
}