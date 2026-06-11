#include<iostream>
using namespace std;
int main()
{
  int L,R,d,count=0;
  cin>>L>>R>>d;
  while(L<=R)
  {
  	if(L%d==0)
  		count++;
  	L++;	
  }
  cout<<count<<endl;
  return 0;
} 