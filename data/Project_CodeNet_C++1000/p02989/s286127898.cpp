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
    
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    
    sort(d.begin(),d.end());
    
    cout << d[n/2] - d[n/2-1] << endl;
    
    
    return 0;
}


