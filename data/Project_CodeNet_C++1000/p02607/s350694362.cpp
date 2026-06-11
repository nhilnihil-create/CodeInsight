#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{
    int n;
    cin>>n;
    int arr[n];
   int counter=0;
    for(int i =1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i =0;i<=n;i++)
    {
      if(arr[i]%2!=0&&i%2!=0)
        counter++;
    }
    cout<<counter;
    return 0;
}
