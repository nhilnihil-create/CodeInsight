#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin  >> s >> t;
    string ans = "";
    for(int i=0;i< n;i++){
         ans  += s.substr(i,1)+ t.substr(i,1);
    }
    cout  <<  ans << endl;
    return 0;
}