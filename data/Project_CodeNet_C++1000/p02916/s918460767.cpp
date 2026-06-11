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
    
    vector<int> a(n),b(n),c(n-1);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n) {
        cin >> b[i];
    }
    rep(i,n-1) {
        cin >> c[i];
    }
    
    int sum = 0;
    rep(i,n-1) {
        sum += b[a[i]];
        if(a[i+1] - a[i] == 1)
            sum += c[a[i]];
    }
    sum += b[a[n-1]];
    
    cout << sum << endl;
    
    
    return 0;
}


