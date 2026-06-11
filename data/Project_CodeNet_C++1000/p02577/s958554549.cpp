#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string n;
  cin>>n;
  
  int nlen=n.size();
  int nsum=0;
  for(int i=0; i<nlen; i++){
    int ni=n.at(i)-'0';
    nsum += ni;
  }
  
  if(nsum%9==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}