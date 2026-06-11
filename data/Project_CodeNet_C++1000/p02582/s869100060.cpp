#include <bits/stdc++.h>
using namespace std;

//const int mxN = 2e5+9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int ans2 = 0;
    string s; cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]=='R'){++ans;}
        else{
            ans = 0;
        }
        ans2 = max(ans,ans2);
    }
    cout << ans2 << endl;
    return 0;
}
