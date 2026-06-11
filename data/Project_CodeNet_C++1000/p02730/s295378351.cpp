#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int t = s.size();
    int f = ( t - 1 ) / 2;
    int l = ( t + 3 ) / 2;

    string fs;
    string ls;

    for ( int i = 0; i < f; ++i ) {
        fs += s[i];
    }

    for ( int i = l-1; i < t; ++i ) {
        ls += s[i];
    }

    if ( fs == ls ) puts("Yes");
    else puts("No");
}