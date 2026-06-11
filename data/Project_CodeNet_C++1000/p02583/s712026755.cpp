#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lld long long int
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
sort(arr,arr+n);
int c=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<j;k++)
        {
            if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&(arr[j]+arr[k])>arr[i])
            c++;
        }
    }
}
cout<<c<<"\n";
	return 0;
}

