#include<iostream>
using namespace std;
int main(){
 int n,o;
  cin>>n;
  o=n%10;
  if(o==2||o==4||o==5||o==7||o==9)
    cout<<"hon";
 else if(o==0||o==1||o==6||o==8)
    cout<<"pon";
  else
    cout<<"bon";
  return 0;
}
  