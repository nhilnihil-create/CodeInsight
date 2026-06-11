#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n+1]={0};
	for(int i=1; i<n; i++){
		int boss;
		cin>>boss;
		arr[boss]++;
	}
	for(int i=1; i<=n; i++) cout<<arr[i]<<'\n';
}