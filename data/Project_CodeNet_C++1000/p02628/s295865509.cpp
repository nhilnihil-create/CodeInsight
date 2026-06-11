#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n;
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int total=0;
	for(int i=1;i<=k;i++){
		total+=a[i];
	}
	cout<<total<<endl;
}