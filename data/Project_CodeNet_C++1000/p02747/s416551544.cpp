/*
      author : nishi5451
      created: 12.08.2020 15:15:53
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    if(s.size()%2!=0) {
        cout << "No" << endl;
        return 0;
    }
    rep(i,s.size()){
        if(i%2==0 && s[i]=='h')
            continue;
        if(i%2==1 && s[i]=='i')
            continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}