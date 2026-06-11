#include <bits/stdc++.h>
#define int long long
using namespace std; 

std::vector<int> v[26];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s , t;
    cin >> s >> t;
    
    int n = s.size();
    int m = t.size();

    int h[26] = {};
    int c = 0;
    for(auto x : s){
        h[x - 'a']++;
        v[x - 'a'].push_back(c++ + 1);
    }

    for(auto x : t){
        if(h[x - 'a'] == 0){
            cout << -1 << "\n";
            return 0;
        }
    }
    int pos = 0;
    int ans = 0;

   /*for(int i = 0 ; i < 26 ; i++){
        if(v[i].size() == 0) continue;
        cout << (char)(i + 'a') << "--> ";
        for(auto x : v[i]) cout << x << " ";
        cout << endl;
    }*/

    for(auto x : t){
        int curr = x - 'a';
        int u = (upper_bound(v[curr].begin() , v[curr].end() , pos) - v[curr].begin());
     // cout << x << " " << u << " " << v[curr][u] << endl;
        if(u == v[curr].size()){
            ans += n - pos + v[curr][0];
            pos = v[curr][0];
        }else ans += v[curr][u] - pos  , pos = v[curr][u];
    }

    cout << ans << endl;

    return 0;
}
