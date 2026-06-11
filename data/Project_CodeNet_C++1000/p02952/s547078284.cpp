#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    if(n >= 10) {
        ans += 9;
        if(n >= 1000) {
            ans += 900;
            if(n >= 100000) {
                ans += 90000;
            }
            else if(n >= 10000){
                ans += n - 9999;
            }
        }
        else if(n >= 100){
            ans += n - 99;
        }
    }
    else {
        ans += n;
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
