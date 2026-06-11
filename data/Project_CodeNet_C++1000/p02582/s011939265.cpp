//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cin >> s;
    if(s == "RRR") cout << 3 << endl;
    else if(s == "SSS") cout << 0 << endl;
    else if(s == "SRS" || s == "RSR" || s == "RSS" || s == "SSR") cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}