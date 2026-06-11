#include <bits/stdc++.h>
using namespace std;

string solve(string s){
    string res = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '?'){
            res += 'D';
        }else{
            res += s[i];
        }
    }
    return res;
}


int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}