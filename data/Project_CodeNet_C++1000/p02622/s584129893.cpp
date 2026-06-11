#include <bits/stdc++.h>
using namespace std;
string s,t;

int main(){
    cin >> s >> t;
    int n = s.length();
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
