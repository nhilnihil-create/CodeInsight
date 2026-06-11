#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int min(vector<int> x) {
    int min = -1;
    rep(i, x.size()) {
        if(min == -1 || min > x[i])
            min = x[i];
    }
    return min;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    vector<int> x(M);
    vector<int> y(M);
    vector<int> c(M);

    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];
    rep(i, M) cin >> x[i] >> y[i] >> c[i];
    int amin = min(a);
    int bmin = min(b);
    int ans = amin+bmin;

    rep(i,M){
        ans = min(ans,a[x[i]-1]+b[y[i]-1]-c[i]); 
    }
    cout << ans <<endl;
}