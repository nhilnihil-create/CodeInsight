#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool a = true;
    for(int i=1;i<4;i++){
        if(s[i] == s[i-1]) a = false;
    }
    if(a) cout << "Good" << endl;
    else cout << "Bad" << endl;
}