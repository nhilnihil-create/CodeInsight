#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int arr[n]={0};
    for(int i=1;i<n;i++)
    {
    for(int j=i+1;j<=n;j++)
    {
    int k=min(j-i,abs(x-i)+1+abs(j-y));
    arr[k]++;
    }
    }
    for(int i=1;i<n;i++)
    cout<<arr[i]<<endl;
	return 0;
}