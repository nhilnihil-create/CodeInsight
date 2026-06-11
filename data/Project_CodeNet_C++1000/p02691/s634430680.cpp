#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long int ans=0;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
    
    map<long long int,long long int> m1,m2;
    
    for(int i=0;i<n;i++)
    {
    m1[i+a[i]]++;
    m2[i-a[i]]++;
    }

    for(auto it:m1)
    {
    ans+=(it.second)*(m2[it.first]);
    }
    cout<<ans;
    return 0;
}