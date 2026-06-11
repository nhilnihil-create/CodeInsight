#include<bits/stdc++.h>
using namespace std;

#define LL long long
set<string> st;
map<string , int> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, mx=0; cin >> n; 
    while(n--) {
        string s; cin >> s;
        mp[s]++;
        mx = max(mx, mp[s]);
    }    

    for(auto x : mp) if(x.second == mx) st.insert(x.first);
    for(auto x : st) cout << x << '\n';
}