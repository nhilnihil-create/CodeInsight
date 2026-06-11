//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,l;
	cin>>n>>l;
	
	int sm = 0;
	for(int i=1;i<=n;i++){
		int x = i+l-1;
		sm += x;
	}
	
	int ans = -1,mn = 1000000;
	for(int i=1;i<=n;i++){
		int x = i+l-1;
		if( abs(sm - (sm-x)) < mn ){
			mn = abs(sm-(sm-x));
			ans = sm-x;
		}
	}
	
	cout<<ans;
	
	return 0;
}
