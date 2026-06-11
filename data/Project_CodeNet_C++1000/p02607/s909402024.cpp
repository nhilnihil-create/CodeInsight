#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include <stdlib.h>
using namespace std;
int main()
{

int n,nn,counter=0; 
cin>>n; 
for (int i=0;i<n;i++)
{
      cin>>nn; 
      if (nn%2!=0 &&(i+1)%2!=0)
      {
      counter++;
      }
}
cout<<counter; 
	return 0;
}