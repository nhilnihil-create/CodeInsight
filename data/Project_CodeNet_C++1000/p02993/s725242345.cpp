#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    bool flg = true;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1]) flg = false;
    }
    if(flg) cout << "Good" << endl;
    else cout << "Bad" << endl;
    return 0;
}