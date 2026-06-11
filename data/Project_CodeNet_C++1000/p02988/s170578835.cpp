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
    
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    
    int cnt = 0;
    rep(i,n-2) {
        if((p[i] <= p[i+1] && p[i+1] <= p[i+2]) ||
           (p[i] >= p[i+1] && p[i+1] >= p[i+2]))
            cnt++;
    }
    
    cout << cnt << endl;
    
    
    return 0;
}


