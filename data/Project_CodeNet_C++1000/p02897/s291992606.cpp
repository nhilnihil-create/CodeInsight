#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    int n;
    cin >> n;

    double ans;

    if(n % 2 == 0) ans = (double)(n / 2.0) / n;
    else ans =  (double) ((n / 2) + 1) / n;

    cout<<fixed<<setprecision(6)<<ans<<endl;

    return 0;
    
}