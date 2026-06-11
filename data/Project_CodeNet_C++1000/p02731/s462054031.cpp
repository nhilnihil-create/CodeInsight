#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    double l;
    cin >> l;
    double x = l / 3;
    double ans = pow(x,3);
    printf("%.10f\n", ans);
    return 0;
}
