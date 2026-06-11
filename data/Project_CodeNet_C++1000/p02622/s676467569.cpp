#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

string s,t;



void solve(){
    
    cin >> s >> t;
    int l = s.length();

    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if(s.at(i) != t.at(i)) ans++;
    }
    
    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}