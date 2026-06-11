#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin >> s;
    bool test = false;
    for(int i=0; i<s.size(); i++){
       if(s[2]==s[3] && s[4]==s[5])
          test = true;
    }
    if(test) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}