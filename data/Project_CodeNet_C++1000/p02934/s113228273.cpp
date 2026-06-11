#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    double ans = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans += 1.0 / a;
    }
    ans = 1.0 / ans;
    cout << setprecision(16) << ans << endl;
   return 0;
}