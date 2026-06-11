#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count{};
    for(int i=0;i<n-2;i++)
    {
        if(arr[i+1]>arr[i] && arr[i+2]>arr[i+1])
            count++;
        if(arr[i+1]<arr[i] && arr[i+2]<arr[i+1])
            count++;
    }
    cout<<count;
	return 0;
}