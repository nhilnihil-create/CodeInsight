#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    int n,k; cin >> n >> k;
    double Max = -1;
    vector<double> p(n);
    rep(i,n) cin >> p[i];

    vector<double> s(n+1,0);
    rep(i,n) s[i+1] = s[i] + (p[i]+1)/2;

    rep(i,n+1-k){
        Max = max(Max,s[i+k] - s[i]);
    }

    cout << fixed << setprecision(13) << Max;

    return 0;
}









