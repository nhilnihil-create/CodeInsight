#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n];
    cin>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    int count =0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>=(1.0*sum/(4.0*m)))
            {
                count++;
            }
    }
    if(count>=m)
    {
        cout<<"Yes"<<endl;

    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
