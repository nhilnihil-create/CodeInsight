#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int arr[m];
	int total = 0;
	for(int i=0; i<m; i++) cin>>arr[i];
	for(int i=0; i<m; i++) total+=arr[i];
	if(total>n) cout<<-1;
	else cout<<n-total;
}