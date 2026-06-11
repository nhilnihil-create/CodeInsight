#include<iostream>
using namespace std;
int main(){
string a;
  cin>>a;
  int f=1;
  for(int i=0;i<3;i++)
  {
    if(a[i]==a[i+1]){
    f=0;
      break;
    }
  }
  if(f==0)
    cout<<"Bad";
  else
    cout<<"Good";
}