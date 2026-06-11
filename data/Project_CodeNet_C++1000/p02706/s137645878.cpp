#include <iostream>

using namespace std;
int main()
{
    int n,m,sum=0,i;
    cin>>n>>m;
    int arr[m];
    for(i=0;i<m;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum<=n)
        cout<<n-sum<<endl;
    else
        cout<<"-1"<<endl;
   return 0;
}
