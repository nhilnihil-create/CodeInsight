#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			int val=a[i]+a[j];
			int p=lower_bound(a,a+n,val)-a;
			cnt+=p-j-1;
		}
	}
	cout<<cnt<<endl;
}