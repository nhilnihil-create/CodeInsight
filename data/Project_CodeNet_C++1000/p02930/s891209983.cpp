#include<bits/stdc++.h>
using namespace std;

long long n,ans[505][505],gap,cont;

int main(){

	cin>>n;
	
	cont=1;
	
	for(int i=0;(1ll<<i)<=n;i++){
		
		gap=(1ll<<i);
		
		for(int j=0;j<gap;j++){
			for(int z=j+1;z<gap;z++){
				if((j+gap)<n && (z+gap)<n){
					ans[j+gap][z+gap]=ans[j][z];
				}
			}
		}
		
		for(int j=0;j<gap;j++){
			for(int z=0;z<gap;z++){
				if((z+gap)<n)
				ans[j][z+gap]=cont;
			}
		}
		
		cont++;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)cout<<ans[i][j]<<" ";
		cout<<"\n";
	}

return 0;
}
