#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int X,Y;
    cin >> X >> Y;
    if(Y%2!=0){
      printl("No");
      return 0;
    }
    int kame = (Y-2*X)/2;
    if(kame>X || kame<0){
      printl("No");
      return 0;
    }
    int tsuru = X - kame;
    if(tsuru>X || tsuru<0){
      printl("No");
      return 0;
    }
    printl("Yes");
}
