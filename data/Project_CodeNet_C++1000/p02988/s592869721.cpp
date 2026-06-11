#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		arr.push_back(p);
	}
	int ans=0;
	for(int j=1;j<n-1;j++){
		vector<int> a={arr[j-1], arr[j], arr[j+1]};
		sort(a.begin(), a.end());
		if(arr[j]==a[1])ans++;
	}
	cout<<ans;
}

