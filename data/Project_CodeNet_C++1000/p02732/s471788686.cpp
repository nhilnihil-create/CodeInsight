#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll arr[200005];
int ball[200005];
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		ball[i] = a;
		arr[a]++;
	}
	ll total = 0;
	for(int i=1; i<=n; i++){
		total+=arr[i]*(arr[i]-1)/2;
	}
	for(int j=0; j<n; j++){
		int i = arr[ball[j]];
		cout<<total-(i-1)<<'\n';
	}
}