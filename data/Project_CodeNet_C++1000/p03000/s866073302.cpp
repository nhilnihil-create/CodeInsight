#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(){
	int n,x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		arr.push_back(l);
	}int sum=0;
	int ans=1;
	for(int j=0;j<n;j++){
		sum+=arr[j];
		if(sum>x) break;
		ans++;
	}
	cout<<ans;
}