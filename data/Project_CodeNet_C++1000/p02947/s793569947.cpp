#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<string> str;
    for(int i=0; i<n; ++i){
        string s; cin >> s; 
        sort(s.begin(), s.end());
        str.push_back(s);
    } 
    map<string, ll> mp;
    for(int i=0; i<n; ++i){
        mp[str[i]]++;
    }
    ll res = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        ll d = (it->second);
        res += d*(d-1)/2;
    }
   
    cout << res << endl;
    return 0;
}