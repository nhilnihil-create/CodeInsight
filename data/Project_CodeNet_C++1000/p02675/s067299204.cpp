#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char l = s[s.length()-1];
    if(l=='3')cout << "bon" << endl;
    else if(l=='0'||l=='1'||l=='6'||l=='8')cout << "pon" << endl;
    else cout << "hon" << endl;
}