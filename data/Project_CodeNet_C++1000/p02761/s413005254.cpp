#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s = "";
    for(int i = 0; i < n; i++) s.push_back('*');
    for(int i = 0; i < m; i++){
        int x, k;
        cin >> x >> k;
        x--;
        if(s[x] != '*' && s[x] != '0' + k) return cout << -1, 0;
        s[x] = char ('0' + k);
        if(x + k == 0 && n > 1) return cout << -1, 0;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '*') s[i] = '0';
    }
    if(s[0] == '0' && n > 1) s[0] = '1';
    cout << s;


    return 0;
}
