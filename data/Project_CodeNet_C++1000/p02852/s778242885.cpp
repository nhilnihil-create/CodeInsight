#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    reverse(s.begin(),s.end());

    int c = 0, r = m;
    vector<int> ans;
    while(1){
        if(r == 0){
            cout << -1 << endl;
            return 0;
        }
        else if(c+r > n || s[c+r] == '1'){
            r -= 1;
        }
        else{
            c += r;
            ans.push_back(r);
            r = m;
            if(c == n) break;
        }
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i == ans.size()-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}