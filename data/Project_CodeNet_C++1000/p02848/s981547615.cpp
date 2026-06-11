#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin>>N>>S;
  for(int i=0;i<S.size();i++){
    if(((int)S.at(i))+N>(int)'Z'){
      S.at(i)=(char)((int)S.at(i)+N-26);
    }
    else{
      S.at(i)=(char)((int)S.at(i)+N);
    }
  }
  cout<<S<<endl;
}
