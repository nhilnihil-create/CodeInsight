//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 1e6 + 5;

int main(){
	
	int n;
	cin>>n;

	int g = 0;

	vector<int>vis(N , 0);
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		g = __gcd(g,x);
		vis[x]++;
	}	

	if(g > 1){
		cout<<"not coprime\n";
	}else{
		bool f = false;
		for(int i=2;i<=N;i++){
			int sum = 0;
			for(int j = i;j<=N;j+=i){
				sum += vis[j];
			}
			if(sum > 1){
				f = true;
				break;
			}
		}
		if(f){
			cout<<"setwise coprime\n";
		}else{
			cout<<"pairwise coprime\n";
		}
	}


	

	return 0;
}