#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[200005];
 
int main()
{  cin>>n>>k;
 
    for(int i=0;i<n;i++)
    {
    	cin>>a[i+1];
    	a[i+1]+=a[i];
	}
	int sum=0;
	for(int i=k;i<=n;i++)
	{ sum=max(sum,a[i]-a[i-k]);
		}
	  
		cout << fixed << setprecision(9) << (double)(sum+k)/2.0;
 
}