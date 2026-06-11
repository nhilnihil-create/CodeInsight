#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> v;
    rep(i,n) {
        double a;
        cin >> a;
        v.push(a);
    }
    rep(i,n-1) {
        double x = v.top(); v.pop();
        double y = v.top(); v.pop();
        v.push((x+y)/2);
    }
    double ans = v.top();
    printf("%.10f\n", ans);
    return 0;
}