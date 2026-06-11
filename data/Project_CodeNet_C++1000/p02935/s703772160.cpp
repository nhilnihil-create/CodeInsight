#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> que;
    rep(i, 0, n){
        double v; cin >> v;
        que.push(v);
    }
    while(true){
        auto p = que.top();
        que.pop();
        auto q = que.top();
        que.pop();
        if(que.empty()){
            cout << (p+q) / 2.0 << endl;
            break;
        }
        que.push((p+q)/2.0);
    }
    return 0;
}