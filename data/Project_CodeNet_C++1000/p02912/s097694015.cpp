#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<double> p_que;
    ll ans = 0;
    rep(i, N){
        double a;
        cin >> a;
        p_que.push(a);
    }
    rep(i, M){
        double val = p_que.top();
        p_que.pop();
        p_que.push(val/2);
    }
    while(!p_que.empty()){
        double val = p_que.top();
        p_que.pop();
        ll num = val;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}