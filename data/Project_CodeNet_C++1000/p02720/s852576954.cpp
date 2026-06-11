#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    queue<ll> qq;
    ll K; cin >> K;
    ll ans;
    for(int i=1;i<=9;i++) qq.push(i);
    for(int i=0; i<K; i++) {
        ll x=qq.front();
        ans = x;
        qq.pop();
        if(x%10!=0) qq.push(10*x+x%10-1);
        qq.push(10*x+x%10);
        if(x%10!=9) qq.push(10*x+x%10+1);
    }
    cout << ans << endl;
}