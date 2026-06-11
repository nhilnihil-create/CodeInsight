#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    double n;
    cin >> n;
    
    int o = (n+1) / 2;
    
    double ans = 1;
    if(o != 0)
        ans = o / n;
    
    cout << fixed << setprecision(8) << ans << endl;
    
    
    
    
    return 0;
}


