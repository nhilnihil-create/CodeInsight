#include<bits/stdc++.h>
using namespace std;
 
#define st string
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 
void solve(){
    st s; cin >> s;
    if(s[2] == s[3] && s[4] == s[5]) cout << "Yes";
    else cout << "No";
}
 
int main(){
    fastio
    solve();
    return 0;
}