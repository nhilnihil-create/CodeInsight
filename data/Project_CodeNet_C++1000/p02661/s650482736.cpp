#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int arr[N];
int brr[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>arr[i]>>brr[i];
	}
	sort(arr+1,arr+1+n);
	sort(brr+1,brr+1+n);
	if(n%2==0) 	cout<<brr[n/2]+brr[n/2+1]-arr[n/2]-arr[n/2+1]+1<<endl;
	else  cout<<brr[(n+1)/2]-arr[(n+1)/2]+1<<endl;
	return 0;
}