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
    
    vector<int> b(n-1);
    rep(i,n-1) {
        cin >> b[i];
    }
    
    int sum = 0;
    vector<int> a(n);
    rep(i,n) {
        if(i == 0)
            a[i] = b.front();
        else if(i == n-1)
            a[i] = b.back();
        else
            a[i] = min(b[i-1],b[i]);
    }
    
    rep(i,n) {
        sum += a[i];
    }
    
    cout << sum << endl;
    
    
    
    
    return 0;
}


