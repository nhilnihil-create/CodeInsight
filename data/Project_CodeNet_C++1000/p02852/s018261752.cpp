#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int now = n;
    vector<int> ans;
    while(now != 0){
        bool end = true;
        for(int j = m; j >= 1; j--){
            if(now < j) continue;
            if(s[now-j] == '0'){
                now -= j;
                end = false;
                ans.push_back(j);
                break;
            }
        }
        if(end){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto p:ans) cout << p << " ";
    cout << endl;
    return 0;
}