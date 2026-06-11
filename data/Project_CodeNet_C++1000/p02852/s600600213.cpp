#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int now = n;
    vector<int> ans;
    while (now > 0){
        bool found = false;
        for(int i=min(now, m); i>0; i--){
            if (s[now-i] == '0'){
                // cout << now << " " << i << " " << s[now-i] << endl;
                ans.push_back(i);
                now -= i;
                found = true;
                break;
            }
        }
        if(!found){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[ans.size() - i - 1];
        if(i != ans.size()-1) cout << " ";
    }
    cout << endl;

    return 0;
}