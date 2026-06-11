#include <iostream>
#include<set>
using namespace std;
int main(void){
    // Your code here!
  int n,a,b;
  cin>>n>>a>>b;
  
  if(a<=b-(b%n))
  cout<<"OK";
  else
    cout<<"NG";
}
