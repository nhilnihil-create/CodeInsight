#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n,cnt=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n-1;i++){
		int x=a[i];
		vector<int> v={a[i-1],a[i],a[i+1]};
		sort(v.begin(), v.end());
		if(v[1]==x)cnt++;
	}
	cout<<cnt;
}