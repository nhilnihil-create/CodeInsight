/*
      author : nishi5451
      created: 11.08.2020 21:54:50
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    if(s[3]==s[2] || s[2]==s[1] || s[1]==s[0])
        cout << "Bad" << endl;
    else cout << "Good" << endl;
    return 0;
}