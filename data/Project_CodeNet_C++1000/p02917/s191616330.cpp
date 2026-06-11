#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{

    int n;
    cin>>n;

    int ans[n];
    int arr[n-1];

    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }

    ans[0] = arr[0];
    int sum = ans[0];
    for(int i=1;i<n-1;i++)
    {
        ans[i] = min(arr[i],arr[i-1]);
        sum+=ans[i];
    }
    sum+=arr[n-2];
    cout<<sum<<endl;

    return 0;
}
