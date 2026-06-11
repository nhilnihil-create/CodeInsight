#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
using pqi = priority_queue<int>;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    pqi q;
    int a;
    rep(i,n){
        cin >> a;
        q.push(a);
    }
    rep(i,m){
        a=q.top();
        q.pop();
        a/=2;
        q.push(a);
    }
    ll ans = 0;
    rep(i,n){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}
