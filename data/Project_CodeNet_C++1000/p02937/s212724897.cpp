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
    // last['d'-'a'][i] は i 文字目より真に後に最初に 'd' が出てくる場所
    // 次のループに突入もする、-1 か i 以上かどっちか
    // last[x][0] != -1 <=> s に x がいる
    vector<vector<int>> last(26, vector<int>(s.size(), -1));

    for(int i=0; i<s.size(); i++){
        for(int j=i; j>=0 && last[s[i]][j] == -1; j--){
                last[s[i]][j] = i;
        }
    }
    for(int i=0; i<26; i++){
        if(last[i][s.size()-1] == -1 && last[i][0] != -1){
            last[i][s.size()-1] = s.size() + last[i][0];
            for(int j=s.size()-2; j>= 0 && last[i][j] == -1; j--){
                last[i][j] = last[i][j+1];
            }
        }
    }

    // あるかどうか
    for(int i=0; i<t.size(); i++){
        if(last[t[i]][0] == -1){
            cout << -1 << endl;
            return 0;
        }
    }


    // 最小
    int ans = -1;  // あほ
    for(int i=0; i<t.size(); i++){
        ans += last[t[i]][(ans+1) % s.size()] - ((ans+1) % s.size()) + 1;
    }

    cout << ans + 1 << endl;

    return 0;

}
