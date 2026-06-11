#include <bits/stdc++.h> 

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> a(n+1,0);
	int b[n];
	long long s=0ll;
	for(int i=0;i<n;i++){
		cin>>b[i];
		s+=a[b[i]];
		a[b[i]]++;
	}
	for(int i=0;i<n;i++){
		cout<<s-a[b[i]]+1ll<<endl;
	}
}
