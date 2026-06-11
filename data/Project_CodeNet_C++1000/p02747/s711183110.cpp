#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool flag = false;
    string hitachi = "";
    for(int i=0; i<5; i++){
        hitachi += "hi";
        if(s == hitachi) flag = true;
    }

    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}