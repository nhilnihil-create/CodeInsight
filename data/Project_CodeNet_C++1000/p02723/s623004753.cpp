#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string str, ans = "No";
    cin >> str;

    if(str.at(2)== str.at(3) && str.at(4) == str.at(5)) ans ="Yes";
    cout << ans << endl;
}