#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll ans = 0;
    priority_queue<int> que;
    rep(i, n){
        cin >> a[i];
        ans += a[i];
        que.push(a[i]);
    }
    rep(i, m){
        int x = que.top();
        que.pop();
        ans -= x - x / 2;
        que.push(x / 2);
    }
    cout << max(ans, 0ll) << endl;
}