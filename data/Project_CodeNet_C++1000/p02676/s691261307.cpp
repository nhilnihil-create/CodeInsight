#include <bits/stdc++.h>

using namespace std;

int main (){

    int x;
    string s;

    cin  >> x;
    cin >> s ;

    if(s.size() <= x){
        cout << s;
    } else{
        cout << s.substr(0,x) << "...";
    }

    return 0;   
}