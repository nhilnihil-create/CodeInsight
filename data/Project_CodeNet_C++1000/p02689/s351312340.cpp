#include <bits/stdc++.h>
int com[100001];
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	long long arr[n+1];
	for(int i=1; i<=n; ++i){
		cin >> arr[i];
	}
	int a, b;
	for(int i=1; i<=m; ++i){
		cin >> a >> b;
		if(arr[a]>arr[b]){
			com[b]=1;
		}
		else if(arr[b]>arr[a]){
			com[a]=1;
		}
		else{
			com[a]=1;
			com[b]=1;
		}
	}
	int count=0;
	for(int i=1; i<=n; ++i){
		if(com[i]==0){
			count++;
		}
	}
	cout << count;
}
