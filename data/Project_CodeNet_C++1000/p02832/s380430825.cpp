#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
 
const int N = 200005;
 
int a[N];
int c[N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i] = -1000000;
	}
	
	for(int i=1;i<=n;i++){
		c[a[i]] = max(c[a[i]],c[a[i]-1]+1);
		ans = max(ans,c[a[i]]);
	}
	
	if(ans == 0){
		cout<<-1;
		return 0;
	}
	cout<<n-ans;
	
	return 0;
}
