#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    map<char,int> m;
    rep(i,4) m[s[i]]++;
    int cnt = 0;
    for(auto p : m) if(p.second == 2) cnt++;
    if(cnt == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}