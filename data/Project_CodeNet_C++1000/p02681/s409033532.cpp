#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    bool ans = false;
    for(int i=0; i<s.size(); i++){
        if(s.at(i) != t.at(i))  ans = true;
    }

    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}