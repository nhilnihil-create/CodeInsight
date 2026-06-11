#include <bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  int X;
  X=S.size();
  if(S.at(X-1)=='s'){
    cout<<S+"es"<<endl;
  }else if(S.at(X-1)!='s'){
    cout<<S+"s"<<endl;
  }
}
