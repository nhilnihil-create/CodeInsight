#include <iostream>

using namespace std;

int main()
{
    int n,x,count =0;
    cin>>n;
    if(n>0)
    {
       int arr[n];
    for(int i=0 ;i<n;i++)
    {

        cin>>x;
        if(x<=100)
            arr[i]=x;
    }
     for(int i=0 ;i<n;i+=2)
    {
      if(arr[i] %2 !=0)
        count++;
    }
    cout<<count;
    }

    return 0;
}
