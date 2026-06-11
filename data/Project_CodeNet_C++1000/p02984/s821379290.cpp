#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    int x1 = 0;
    int s = 0;
    rep(i,n)s += a[i];
    for(int i = 1;i < n;i+=2)x1+= a[i];
    x1 = s - 2*x1;
    vector<int> ans;
    ans.push_back(x1);
    rep(i,n-1){

        int x = 2*a[i] - ans.back();
        ans.push_back(x);
    }
    for(auto p:ans)cout << p << endl;
    return 0;
}