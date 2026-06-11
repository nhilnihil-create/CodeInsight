#include<iostream>
using namespace std;
int main()
{int x;
 cin>>x;
  for(int i=400,j=9;i<2001;i+=200,j--){
    if(x<i)
    {cout<<j;
     break;}}
 return 0;}
