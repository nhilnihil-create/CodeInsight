#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    string prev = "";
    string cur = "";
    for(int i = 0; i < s.size(); i++){
        cur += s[i];
        if(cur != prev){
            ans++;
            prev = cur;
            cur = "";
        }
    }
    cout << ans << endl;
}