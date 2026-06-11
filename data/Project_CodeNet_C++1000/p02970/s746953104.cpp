#include<iostream>
using namespace std;
int main(){
  int N,D;
  cin>>N>>D;
  cout<<N/(2*D+1)+(N%(2*D+1)==0?0:1)<<endl;
  return 0;
}