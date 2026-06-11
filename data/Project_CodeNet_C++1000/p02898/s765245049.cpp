//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int cnt = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x >= m)cnt++;
	}
	cout<<cnt;
	
	return 0;
}
