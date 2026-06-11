#include<bits/stdc++.h>
using namespace std;
using Long = long long;

int main(){
    string s;
    cin >> s;
    int t = 0;
    for( char cc : s ) t += cc - '0';
    if( t % 9 == 0 ) cout << "Yes";
    else cout << "No";
    return 0;
}