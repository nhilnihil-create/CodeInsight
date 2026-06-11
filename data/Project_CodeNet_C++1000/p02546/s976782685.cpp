#include<iostream>
#include <string.h>
using namespace std;
int main()
{
  char w[1000];
  cin>>w;
  int l = strlen(w);
  if (w[l-1]=='s')
  cout<<w<<"es";
  else cout<<w<<'s';
}
  