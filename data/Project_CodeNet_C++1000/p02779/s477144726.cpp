#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
