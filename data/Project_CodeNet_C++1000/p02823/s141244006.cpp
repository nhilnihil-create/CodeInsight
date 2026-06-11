#include <iostream>
using namespace std;
int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  if(abs(a-b)%2==0){
    cout<<abs(a-b)/2<<endl;
  }else{
    cout<<min(abs(a-1)+1+abs(abs(a-b)-1)/2,abs(n-b)+1+abs(abs(a-b)-1)/2)<<endl;
  }
  return 0;
}
