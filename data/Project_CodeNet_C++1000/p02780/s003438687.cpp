#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,double>> a;
    rep(i,n){
        int p;
        cin >> p;
        a.emplace_back(p,(double)(1+p)/2);
    }
    vector<double> e(n);
    e.at(0) = a.at(0).second;
    cout << fixed << setprecision(10);
    for(int i = 1 ; i < n;i++){
        e.at(i) = e.at(i-1) + a.at(i).second;
    }
    double ans = e.at(k-1);
    for(int j = 0; j + k < n;j++){
        double t = e.at(j + k) - e.at(j);
        ans = max(ans,t);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}