#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
 int n,m;
 cin>>n>>m;
 vector<int> data(n);
    rep(i,m) {
        int a;
        cin >> a;
        data.at(a) = 1;
    }
    
    vector<long long> dp(n+2);
    int mod = 1000000007;
    dp.at(n) = 1;
    for(int i = n -1;i>=0;i--) {
     if(data.at(i) == 1) {
      dp.at(i) = 0;
     continue;
     }
        dp.at(i) = (dp.at(i+1) + dp.at(i+2)) % mod;
    }
    cout << dp.at(0);

}
