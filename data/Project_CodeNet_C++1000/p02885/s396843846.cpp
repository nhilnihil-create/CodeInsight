#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    int ans = a - b * 2;
    if(ans < 0) {
        cout << 0 << endl;
    }
    else
        cout << ans << endl;
    
    
    
    return 0;
}
