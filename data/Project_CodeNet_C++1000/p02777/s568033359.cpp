#include<iostream>
using namespace std;
main(){
  string a,b,c;
  int int_a,int_b;
  cin>>a>>b>>int_a>>int_b>>c;
  if(c==a)cout<<int_a-1<<" "<<int_b<<endl;
  else cout<<int_a<<" "<<int_b-1<<endl;
  return 0;
}