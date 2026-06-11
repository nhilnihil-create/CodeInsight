#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

using ll = long long;

int main(){
    ll X;
    cin >> X;

    ll amount = 100;
    ll passYear = 0; 
    while(true){
      if(amount>=X){
        printl(passYear);
        return 0;
      }
      passYear++;
      amount+= amount /100;
    }
}
