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
	vector<int>arr(n);
	vector<int>memo(2001);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		memo[arr[i]]++;
	}
	for(int i=1; i<=2000; i++){
		memo[i]+=memo[i-1];
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
			 continue;
			int upper=(arr[i]+arr[j]-1);
			int lower=abs(arr[i]-arr[j])+1;
			int temp=memo[upper]-memo[lower-1];
			if(arr[i]<=upper && arr[i]>=lower)
			 temp--;
			if(arr[j]<=upper && arr[j]>=lower)
			 temp--;
		//	cout<<" i , j , temp :  "<<arr[i]<<" "<<arr[j]<<" "<<temp<<"\n";
			ans+=temp;
		}
	}
	ans/=6;
	cout<<ans;
	return 0;
}