#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for(int i = 0 ; i < s.length(); i++){
        char c = s[i];
        if(c >= 'a' && c <= 'z'){
            s[i] -= 'a' - 'A';
            continue;
        }
        if(c >= 'A' && c <= 'Z'){
            s[i] += 'a' - 'A';
            continue;
        }
    }
    cout << s << endl;
    return 0;
}

