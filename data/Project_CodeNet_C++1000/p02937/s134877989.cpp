#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s,t;

    cin >> s >> t;
    vector<vector<int>> pos(26);
    for(int i=0;i<s.size();i++) pos[s[i]-'a'].push_back(i);
    for(int i=0;i<s.size();i++) pos[s[i]-'a'].push_back(i+s.size());

    ll ans = 0;
    int p = -1;
    for(int i=0;i<t.size();i++){
        int c = t[i]-'a';
        auto itr = upper_bound(pos[c].begin(), pos[c].end(), p);
        if(itr==pos[c].end()){
            cout << -1 << endl;
            return 0;
        }

        int npos = *itr;
        if(npos>=s.size()){
            ans += s.size();
            p = npos - s.size();
        }else{
            p = npos;
        }
        
    }

    cout << ans + p + 1 << endl;
}