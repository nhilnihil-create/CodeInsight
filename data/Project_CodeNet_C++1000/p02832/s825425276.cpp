//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>>arr[i];
    int k=1;
    int flag=0;
    int cnt=0;
    for(i=0; i<n; i++)
    {
       if(arr[i]==k)
         {
            flag=1;
           cnt++;
           k++;
         }
    }
    if(flag==0)
        cout<<-1;
    else
        cout<<n-cnt;
    return 0;
}