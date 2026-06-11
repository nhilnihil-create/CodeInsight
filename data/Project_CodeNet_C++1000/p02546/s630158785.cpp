#include <bits/stdc++.h>
using namespace std;;

int main(){
    string s;
    cin >> s;
    int n;
    n = s.length();
    if (s.at(n-1) == 's'){
        cout << s << "es" << endl;
    }else{
        cout << s << 's' << endl;
    }
}