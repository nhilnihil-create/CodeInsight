#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin>>N;
  int ans=N%10;
  if(ans==2||ans==4||ans==5||ans==7||ans==9)
  { 
    cout<<"hon"<<endl;
  }
  else if(ans==0||ans==1||ans==6||ans==8)
  {
    cout<<"pon"<<endl;
  }
  else if (ans==3)
  {
  cout<<"bon"<<endl;
}
  return 0;
}
