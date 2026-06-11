#include <bits/stdc++.h>
typedef long long ll;
const int inf = 1e9;
using namespace std;






int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int cnt = 1e9;
    for(int i = 0; i < s.size(); i++){
        int ans = 0;
        for(int j = 0; j < t.size(); j++){
            if(i+j >= s.size()){
                ans = 1e9;
                break;
            }
            if(s[i+j] != t[j]){
                ans++;
            }
        }
        cnt = min(ans, cnt);
    }
    cout << cnt << '\n';

    return 0;
}
