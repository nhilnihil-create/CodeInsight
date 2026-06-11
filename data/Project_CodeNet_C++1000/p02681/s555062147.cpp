#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    t=t.substr(0,t.length()-1);
    if(s==t)cout << "Yes" << endl;
    else cout << "No" << endl;


}