#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    string t;
    cin >>s;
    cin >>t;
    if (t.substr(0,s.size())==s){
        cout <<"Yes";
    }
    else {
        cout <<"No";
    }
}
