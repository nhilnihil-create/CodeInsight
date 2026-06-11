#include <iostream>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n,k,s=0; cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n-k;i++)
        s+=arr[i];
    cout<<s;
}
