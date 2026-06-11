#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int main(){
    cin >> s >> t;
    int len1 = s.size();
    int len2 = t.size();
    int ans = 0;
    for(int i = len1 - len2;i>=0;i--){
        int cnt = 0;
        for(int j = 0;j<len2;j++){
            if(s[i + j] == t[j]) {
                cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << len2 - ans << endl;

    return 0;
}