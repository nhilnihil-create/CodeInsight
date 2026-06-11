#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int N;
  cin >> N;
  cin>>S;
  int count=0;
  while(S.size()){
    if(S.substr(0,3)=="ABC"){
      S=S.substr(3);
      count++;
      continue;
    }
    S=S.substr(1);
  }
  
  cout << count << endl;
}