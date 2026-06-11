#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    rep(i,n){
        cin >> height[i];
    }
    long long ans = 0;
    map<int,int> mp;
    rep(i,n){
        int sa = i - height[i];
        int wa = i + height[i];
        ans += mp[sa];
        mp[wa]++;
    }
    cout << ans << endl;
}