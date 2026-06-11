#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

string s[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        mp[s[i]]++;
    }
    int mx = 0;
    for(int i = 0; i < n; i++){
        mx = max(mx, mp[s[i]]);
    }
    set<string>st;
    for(int i = 0; i < n; i++) if(mp[s[i]] == mx) st.insert(s[i]);
    for(auto i: st) cout << i << '\n';


    return 0;
}
