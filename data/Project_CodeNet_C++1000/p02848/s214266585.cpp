/*
      author  : nishi5451
      created : 15.08.2020 13:11:41
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

    rep(i,s.size()){
        int k = (s[i]-'A'+n)%26;
        s[i]='A'+k;
    }
    cout << s << endl;
    return 0;
}