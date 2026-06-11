#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    int R = 0, ans = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == 'R') R++;
    
    for(int i = 0; i < R; i++)
        if(s[i] != 'R') ans++;
    
    cout << ans << "\n";
    return 0;
}