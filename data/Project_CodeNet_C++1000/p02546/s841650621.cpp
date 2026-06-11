#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int l = s.size();
    if(s[l-1] != 's'){
        cout << s + "s" << endl;
    }else{
        cout << s + "es" << endl;
    }
}