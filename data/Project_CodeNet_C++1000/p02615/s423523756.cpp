#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 666666;
int arr[N];
int n;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+1+n,cmp);
	int sum=arr[1];
	int id=2;
	int f=0;
	for(int i=3;i<=n;i++){
		sum+=arr[id];
		f++;
		if(f==2){
			f=0;id++;
		}
	}
	cout<<sum;
	return 0;
}