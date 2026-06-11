/*
      author  : nishi5451
      created : 15.08.2020 13:03:41
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    string s;
    cin >> n >> s;
    if(s.size()%2!=0){
        cout << "No" << endl;
        return 0;
    }
    else{
        string t = s.substr(0,s.size()/2);
        string u = s.substr(s.size()/2,s.size()/2);
        if(t==u) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}   