#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int,int> >arr(n);
	for(int i=0; i<n; i++)
	{
		int num;
		cin>>num;
		arr[i]=make_pair(num,i+1);
	}
	sort(arr.begin(),arr.end());
	for(int i=0; i<n; i++)
	{
		cout<<arr[i].second<<" ";
	}
	return 0;
}