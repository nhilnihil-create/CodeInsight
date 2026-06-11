/*
      author  : nishi5451
      created : 15.08.2020 13:38:22
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<n-2; i++){
        if(s.substr(i,3)=="ABC") ans++;
    }
    cout << ans << endl;
    return 0;
}