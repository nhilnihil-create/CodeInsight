#include <iostream>
using namespace std;

int main(){
 int n;cin>>n;
  bool ok=0;
  
  for(int i=1;i<=9;i++) for(int j=1;j<=9;j++) ok|=(i*j==n);
  
  cout<<(ok?"Yes":"No")<<endl;
}