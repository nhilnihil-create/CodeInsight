#include<iostream>
using namespace std;
int main()
{
  int x[5]={1,2,3,4,5};
  cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
  if(x[0]==0)
  {cout<<"1"<<endl;
  }
  else if(x[1]==0)
  {
    cout<<"2"<<endl;
  }
  else if(x[2]==0)
  {
    cout<<"3"<<endl;
  }
  else if(x[3]==0)
  {
    cout<<"4"<<endl;
  }
  else {
    cout<<"5"<<endl;
  }
  return 0;
}
