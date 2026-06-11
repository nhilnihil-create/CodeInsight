#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> p(n+1);
    vector<double> sum(n+1);
    double ans = 0;
    for(int i = 1; i <= n; i++){
        double a;
        cin >> a;
        p[i] = (a+1)/2;
        sum[i] = sum[i-1] + p[i];   
    }
    for(int i = k; i <= n; i++){
        ans = max(ans, sum[i] - sum[i-k]);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}