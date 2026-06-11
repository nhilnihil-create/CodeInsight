#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s, ss;
    cin >> s >> ss;
    int sz = s.size();
    int ans=0;
    for(int i=0; i<sz; i++){
        if(s[i]!=ss[i])
            ans++;
    }
    cout << ans <<endl;
}

int main(){
   // int t;  cin >> t;   while(t--)
    solve();

    return 0;
}
