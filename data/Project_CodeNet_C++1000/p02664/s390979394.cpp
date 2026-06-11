#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  for(char x: S){
    cout<<(x=='?' ? 'D' : x);
  }
  cout<<endl;
}