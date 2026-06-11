#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    vector<string>sub;
    for(int i = 0; i<s.size(); i++) {
        string subst = "";
        for(int j = i; j<s.size(); j++){
            subst+=s[j];
            sub.push_back(subst);
        }
    }
    int ans = 10000000;
    int cnt = 0;
    for(auto val : sub) {
        if(val.size()==t.size()){
            //cout << val << endl;
        for(int i = 0; i<t.size(); i++) {
            
                if(val[i]!=t[i]) cnt++;
            
        }
        ans = min(ans, cnt);
        cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}