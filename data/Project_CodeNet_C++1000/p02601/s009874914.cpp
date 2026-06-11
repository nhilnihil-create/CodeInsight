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

    ll a,b,c,k;
    cin >> a >> b >> c >> k;

    ll ca = 0;
    ll cc = 0;

    while(b<=a){
        b *= 2;
        ca++;
    }

    // cout << b << "\n";

    while(c<=b){
        c *= 2;
        cc++;
    }

    // cout << ca << "," << cc;

    if(ca+cc <= k){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}