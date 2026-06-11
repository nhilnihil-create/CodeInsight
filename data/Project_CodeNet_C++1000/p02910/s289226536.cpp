/*
      author  : nishi5451
      created : 15.08.2020 12:38:21
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    rep(i,(int)s.size()){
        if((i+1)%2==0){
            if(s[i]=='R'){
                cout << "No" << endl;
                return 0;
            }
        }   
        else{
            if(s[i]=='L'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}