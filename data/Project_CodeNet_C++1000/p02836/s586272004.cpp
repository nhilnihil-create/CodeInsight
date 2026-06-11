#include <iostream>
using namespace std;

int main() 
{
    string str;
    cin>>str;
    int x=str.length();
    int p=x/2;
    int sum=0;
    for(int i=0;i<p;i++)
    {
      if(str[i]==str[x-i-1])
      {
        
      }
      else
      {
        sum++;
      }
    }
    cout<<sum;
}