#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    cout << (a==b.substr(0,b.size()-1)?"Yes":"No");
    return 0;
}