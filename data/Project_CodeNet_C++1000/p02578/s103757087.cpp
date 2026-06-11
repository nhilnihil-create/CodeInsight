#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=0;
	int m=0;
	for(int i=0;i<n;i++){
		m=max(m,a[i]);
		ans+=m-a[i];
	}
	cout<<ans<<endl;
}