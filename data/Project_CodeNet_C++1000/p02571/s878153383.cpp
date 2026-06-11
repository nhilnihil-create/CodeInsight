#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s,t;
    cin >> s >> t;

    int ans = 1005;
    int range = s.size()-t.size();
    for(int i=0;i<=range;i++){
        int cnt = 0;
        for(int j=0;j<t.size();j++){
            if(s[i+j]==t[j]) cnt++;
        }
        cnt = t.size()-cnt;
        ans = min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}