#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    string sub_t;
    sub_t = t.substr(0, s.size());
    //cout << s << " " << sub_t << endl;
    if (sub_t == s){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    } 
}