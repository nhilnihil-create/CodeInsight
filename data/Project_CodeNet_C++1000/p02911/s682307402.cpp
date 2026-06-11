#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<int> re(n+1,k-q);
    rep(i,q) {
        int a;
        cin >> a;
        
        re[a]++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(re[i] > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    
    
    
    
    return 0;
}
