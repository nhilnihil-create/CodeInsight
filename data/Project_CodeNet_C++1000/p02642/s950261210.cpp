#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define MAXN 1000001	
ll spf[MAXN];

void sieve() 
{ 
     
} 


int main(){
		

	ll n;
	cin>>n;
	ll ar[n];
	
	ll *count = new ll[MAXN]();
	for(int i=0;i<n;i++){
	 	cin>>ar[i];
	 	count[ar[i]]++;
	}
	//sort(ar,ar+n);
	int ans=0;
	
	bool *visited = new bool[MAXN]();
	for(int i=1;i<MAXN;i++){
		
		if(count[i]==0||visited[i]){
			continue;
		}
		if(count[i]==1&&!visited[i]){
			ans++;
		}
			
		for(int j=i;j<MAXN;j+=i){
				visited[j] = true;
		}
		
	}	
	
	cout<<ans;
//	cout<<ans;
	
	
	return 0;
}
