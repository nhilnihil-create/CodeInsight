#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> que;
    rep(i, 0, n) {
        double v;
        cin >> v;
        que.push(v);
    }
    rep(i, 0, n-1){
        auto q1 = que.top();
        que.pop();
        auto q2 = que.top();
        que.pop();
        que.push((q1 + q2) / 2);
    }
    printf("%.12lf\n", que.top());
    return 0;
}