#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool ans = false;
    for(int i=0; i<s.size()-1; i++){
        if(s.at(i) == s.at(i+1)) ans = true;
    }

    if(ans) cout << "Bad" << endl;
    else cout << "Good" << endl;
}