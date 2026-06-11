#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n; cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    bool f = true;
    for(pair<int,int> p : mp){
        if(p.second > 1) f = false;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}