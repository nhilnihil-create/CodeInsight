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
    int K;
    string S;
    cin >> K >> S;
    if(S.size()<=K){
      printl(S);
    }else{
      string result = S.substr(0,K) + "...";
      printl(result);
    }
}
