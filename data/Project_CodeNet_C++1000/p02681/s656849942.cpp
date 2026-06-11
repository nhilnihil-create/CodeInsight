/*
      author : nishi5451
      created: 11.08.2020 23:14:55
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s,t;
    cin >> s >> t;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}