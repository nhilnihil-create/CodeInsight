#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = (int)s.size();
    if(s[n-1] != 's'){
        s += 's';
    }
    else{
        s += 'e';
        s += 's';
    }
    cout << s << "\n";
    return 0;
}