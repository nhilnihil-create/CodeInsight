#include "bits/stdc++.h"
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i;
    for(i=0;i<s.length();i++){
        if(s.at(i)>='a'&&s.at(i)<='z'){
            cout << char(s.at(i)+'A'-'a');
        }
        else if(s.at(i)>='A' &&s.at(i)<='Z'){
            cout << char(s.at(i)+'a'-'A');
        }
        else cout << s.at(i);
    }
    cout << endl;
    return 0;
}
