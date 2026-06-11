#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,arr[1005],price=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(int i=0;i<k;i++)
    {
        price+=arr[i];
    }
    cout<<price<<endl;
    return 0;
}
