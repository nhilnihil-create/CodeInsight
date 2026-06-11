#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    ll K; cin >> K;
    queue<ll> q;
    rep(i, 9){
        q.push(i+1);
    }

    ll cnt = 1;
    ll x;
    while(cnt<=K){
        x = q.front(); q.pop();
        if(x%10!=0) q.push(10*x+x%10-1);
        q.push(10*x+x%10);
        if(x%10!=9) q.push(10*x+x%10+1);
        cnt++;
    }
    cout << x << endl;
}