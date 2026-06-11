//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n,m;
	cin>>n>>m;
	int a[n+1];

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>v(n+1,0);
	for(int i=1;i<=n;i++){
		v[i] = v[i-1]+a[i];
	}

	for(int i=0;i<v.size();i++){
		if(v[i]>m){
			cout<<i<<endl;
			return 0;
		}/*if(v[i] == m){
			cout<<i<<endl;
			return 0;
		}*/
	}

	cout<<n+1<<endl;


	

	return 0;
}