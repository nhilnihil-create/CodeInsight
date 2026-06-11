#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin >> S >> T;
  string Judge = T.substr(0,S.size());
  if (Judge == S){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}