#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	cin>>n>>m;
	int sum=0;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
	 cin>>arr[i];
	 sum+=arr[i];
    }
	sort(arr.rbegin(),arr.rend());
	int cnt=0;
	for(int i=0; i<m; i++)
	{
		if(arr[i]>=ceil(sum/(4.0*m)))
		{
			cnt++;
		}
	}
	if(cnt<m)
	 cout<<"No";
	else
	 cout<<"Yes";
	return 0;
}