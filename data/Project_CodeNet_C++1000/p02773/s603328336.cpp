#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int64_t,int64_t>;
int main(){
    int n;
    cin >> n;
    map<string,int> mp;
    rep(i,n){
        string s;
        cin >> s;
        mp[s] ++;
    }
    int mx = 0;
    for (auto v : mp){
        if (v.second > mx){
            mx = v.second;
        }
    }
    for (auto v : mp){
        if (v.second == mx){
            cout << v.first << endl;
        }
    }
}