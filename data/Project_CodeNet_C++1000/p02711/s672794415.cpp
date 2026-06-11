#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool ans = false;
    for(int i=0; i<3; i++){
        if(s.at(i) == '7') ans = true;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}