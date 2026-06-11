#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int ans = 10000;
    for(int i = 0; i <= s.size() - t.size(); i++){
        string str = s.substr(i,t.size());
        int cnt = 0;
        for(int j = 0; j < str.size(); j++){
            if(str[j] != t[j])
                cnt++;
        }
        ans = min(ans,cnt);
    }

    cout << ans << endl;

    return 0;
}