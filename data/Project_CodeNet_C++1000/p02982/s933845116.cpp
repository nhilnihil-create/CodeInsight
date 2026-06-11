#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める
double dist(vector<int> y, vector<int> z, int d){
    int total = 0;
    rep(i,d){
        total += (y[i]-z[i])*(y[i]-z[i]);
    }
    double ans = sqrt(total);
    return ans;
}

bool is_int(double x){
    return floor(x) == x;
}
int main()
{
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i,n)rep(j,d) cin >> x[i][j];
    int ans = 0;
    rep(i,n){
        for (int j = i; j < n; j++)
        {
            if(i == j) continue;
            double di = dist(x[i],x[j],d);
            if(is_int(di)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}