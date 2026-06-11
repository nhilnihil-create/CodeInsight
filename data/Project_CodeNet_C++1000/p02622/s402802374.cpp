#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S,T;
    cin >> S >> T;
    int ans = 0;
    rep(i,S.size()){
      if(S.at(i)!=T.at(i)){
        ans++;
      }
    }
    printl(ans);
}
