#include <iostream>
#include<algorithm>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
   int n,sum=0,maxi=200001;
   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
       if(arr[i]<maxi)
       {
           sum++;
           maxi=arr[i];
       }
   }
   cout<<sum<<endl;
    return 0;
}
