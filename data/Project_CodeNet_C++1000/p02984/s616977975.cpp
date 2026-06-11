#include<bits/stdc++.h>
using namespace std;
long long arr[300005];
long long psum[300005];
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) arr[i+n] = arr[i];
	for(int i=1; i<=2*n; i+=2) arr[i]*=-1;
	for(int i=1; i<=2*n; i++) psum[i]+=psum[i-1]+arr[i];
	for(int i=1; i<=n; i++){
		int fin = i+n-1; 
		long long total = psum[fin]-psum[i-1];
		if(i%2) cout<<total*-1<<" ";
		else cout<<total<<" ";
	}
}