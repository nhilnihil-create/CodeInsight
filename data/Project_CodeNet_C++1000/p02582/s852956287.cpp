#include <bits/stdc++.h>
using namespace std;

#define print cout <<

int main(){
    string S;
    cin >> S;

    int ans = 0;
    int renzoku = 0;
    for(auto c : S){
      if(c=='R'){
        renzoku +=1;
        if(renzoku>ans){
          ans = renzoku;
        }
      }else{
        renzoku = 0;
      }
    }
    print ans << endl;
}
