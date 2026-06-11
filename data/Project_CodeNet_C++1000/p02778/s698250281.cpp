#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {

  string S;cin>>S;
  
  for(int i=0;i<S.size();i++){
    S.at(i)='x';
    cout<<S.at(i);
  }
  cout<<endl;
}
  