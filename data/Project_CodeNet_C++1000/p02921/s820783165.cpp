#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

int main(){

   string s,t;
   cin >> s >> t;

    int ans(0);
    for (int i(0); i < 3; i++) {
        if(s[i] == t[i]) ans++;
    }
    cout << ans << ENDL;

    return 0;
}