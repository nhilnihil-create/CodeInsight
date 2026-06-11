#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string a,b;
  cin>>a>>b;
  char c[2*n];
  for(int i=0,j=0;b[j]!='\0';i++,j++)
  {
    c[i]=a[j];
    c[++i]=b[j];
  }
  c[2*n]='\0';
  for(int i=0;i<2*n;i++)
	cout<<c[i];
  return 0;	
}  