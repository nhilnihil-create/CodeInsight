#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string s, ss;
    cin >> s >> ss;
    int t = s.size();
    int ts = ss.size();
    string ans ="Yes";
    if( t != ts - 1) ans = "No";
    for (int i = 0; i < t; i++){
      if (s.at(i) != ss.at(i)) ans = "No";
    }

    cout <<  ans  << endl;

}