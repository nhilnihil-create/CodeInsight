#include<iostream>
using namespace std;
int main(){
int n;
  cin>>n;
  int i=0;
  while(1000*i-n<0) i++;
  cout<<1000*i-n<<endl;
  return 0;
}