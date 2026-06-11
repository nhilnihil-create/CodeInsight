#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int i,j,k;
  cin>>i>>j>>k;
  
  cout<<min(i,j)+min(max(i,j),k)<<endl;
  return 0;
}
