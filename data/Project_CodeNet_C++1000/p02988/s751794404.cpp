#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
       fast;
       int n;
       cin>>n;
       int arr[n],cnt=0;
       for(int i=0;i<n;i++)
    	cin>>arr[i];
       for(int i=1;i<n-1;i++)
    		if(arr[i]<arr[i-1]&&arr[i]>arr[i+1])
    			cnt++;
    		else if(arr[i]>arr[i-1]&&arr[i]<arr[i+1])
    			cnt++;
    	cout<<cnt;
       return 0;
}
