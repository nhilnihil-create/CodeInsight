#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    map<string,int> mp;
    rep(i,N){
        string S;
        cin >> S;
        mp[S]++;
    }
    int mx = 0;
    for(auto p : mp) mx = max(mx, p.second);
    for(auto p : mp){
        if(p.second != mx) continue;
        cout << p.first << endl;
    }
}