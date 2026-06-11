#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string s;
    string ans ="No";
  
    cin >> s;

    if(s.at(0)== '7') ans = "Yes";
    if(s.at(1)== '7') ans = "Yes";
    if(s.at(2)== '7') ans = "Yes";
    cout <<  ans  << endl;
}