#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
//#define for(i,a,b) for(int i=(a);i<=(b);i++)

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
for(int i=n-1;i>0;i--)
{
    if(arr[i]<arr[i-1])
    {
        if(arr[i]+1==arr[i-1])
        {
            arr[i-1]--;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
}
cout<<"Yes";
}