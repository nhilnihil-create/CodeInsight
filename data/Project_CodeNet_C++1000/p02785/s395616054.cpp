#include<bits/stdc++.h>
using namespace std;
int main(){
	
		long int n,k,sum=0,c;
		cin>>n>>k;
		long int g[n];
		for(int i=0;i<n;i++){
		    cin>>g[i];
		}
		sort(g,g+n);
		for(int i=0;i<n-k;i++){
		    sum+=g[i];
		}
		cout<<sum;
		return 0;
}