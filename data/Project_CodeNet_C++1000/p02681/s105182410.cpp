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
    string S, T;
    cin >> S >> T;
    if(S.size()+1!=T.size()){
      printl("No");
      return 0;
    }
    rep(i,S.size()){
      if(S.at(i)!=T.at(i)){
        printl("No");
        return 0;
      }
    }
    printl("Yes");
}
