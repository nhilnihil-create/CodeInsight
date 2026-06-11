#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    string s, t;
    cin >> s >> t;
    for(int i=0; i<s.size(); i++){
        s[i] -= 'a';
    }
    for(int j=0; j<t.size(); j++){
        t[j] -= 'a';
    }
    
    // あるかどうか
    vector<vector<int>> where(26, vector<int>());

    for(int i=0; i<s.size(); i++){
        where[s[i]].push_back(i);
    }
    

    // あるかどうか
    for(int i=0; i<t.size(); i++){
        if(where[t[i]].size() == 0){
            cout << -1 << endl;
            return 0;
        }
    }


    // 最小
    int ans = -1;
    for(int i=0; i<t.size(); i++){
        auto itr = lower_bound(begin(where[t[i]]), end(where[t[i]]), (ans+1) % s.size());
        int idx = distance(begin(where[t[i]]), itr);
        if(idx == where[t[i]].size()){
            idx = 0;
            ans += s.size();
        }
        ans += where[t[i]][idx] - (ans+1) % s.size() + 1;
        // ans += last[t[i]][(ans+1) % s.size()] - (ans+1) % s.size() + 1;
    }

    cout << ans + 1 << endl;

    return 0;

}