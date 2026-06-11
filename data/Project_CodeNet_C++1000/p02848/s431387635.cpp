#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    for(int i=0; i<s.size(); i++) {
        int a = int(s[i]);
        a += n;
        if( a >= 91)  a -= 26;
        cout << char(a);
    }

    cout << endl;
}