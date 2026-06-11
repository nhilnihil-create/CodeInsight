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
    
    vector<int> ans(n+1);
    rep(i,n) {
        int a;
        cin >> a;
        
        ans[a] = i+1;
    }
    
    for(int i = 1; i < n; i++)
        cout << ans[i] << " ";
    
    cout << ans[n] << endl;
    
    
    
    return 0;
}


