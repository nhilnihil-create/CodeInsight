#include <iostream>
#include<string.h>
using namespace std;


int main()
{
     int n;
     cin>>n;
     string d;
     cin>>d;
  int l=d.size();
    for(int i=0;i<l;i++)
    {
      int x=int(d[i])-65;
      x=(x+n)%26;
      d[i]=(char)(65+x);
    }
  cout<<d<<endl;
     

    return 0;
}
