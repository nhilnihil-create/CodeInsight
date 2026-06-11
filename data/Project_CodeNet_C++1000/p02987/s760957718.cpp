#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i < n; i++)

int main(){
    string s;
    cin >> s;
    set<char> se;
    rep(i, 4){
        se.insert(s[i]);
    }
    if(se.size() != 2){
        cout << "No" << endl;
        return 0;
    }
    char c = s[0];
    int count = 1;
    rep(i, 4){
        if(c == s[i]) count++;
    }
    if(count == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}