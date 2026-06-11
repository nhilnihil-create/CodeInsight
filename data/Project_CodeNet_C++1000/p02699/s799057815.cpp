#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int s, w;
    string ans ="unsafe";
  
    cin >> s >> w;

    if(w < s) ans = "safe";
    cout <<  ans  << endl;
}