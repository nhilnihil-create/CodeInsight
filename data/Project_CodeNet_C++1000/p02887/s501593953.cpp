/*Third*/
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    char ch;
    ch=arr[0];
    int sum=1;
    for(int i=1;i<n;i++)
    {
      if(ch==arr[i])
      {
        
      }
      else
      {
        sum++;
        ch=arr[i];
      }
    }
    cout<<sum;
}