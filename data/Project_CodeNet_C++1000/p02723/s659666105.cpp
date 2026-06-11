#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.size() <  6 || !((s[2]==s[3])&&s[4]==s[5])){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

}
