#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ull arr[100005];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ull b= 1000000000000000000;
	ull hasil = 1;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			cout<<0<<endl;
			return 0;
		}
		if(b/arr[i]== 0){
			cout<<-1<<endl;
			return 0;
		}
		b/=arr[i];
		hasil*=arr[i];
	}
	cout<<hasil<<endl;
}