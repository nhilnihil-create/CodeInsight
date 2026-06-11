#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char,int> m;
    rep(i,4)m[s[i]]++;
    if(m.size()==2 && m[s[0]]==2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
}