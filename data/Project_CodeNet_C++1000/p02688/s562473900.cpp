#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ans = 0;
	
	bool has_snacks[n];
	for(int i=0;i<n;i++){
	    has_snacks[i]=false;
	}
	for(int i = 0; i < k; i++){
	    int d;
	    cin>>d;
	    for(int j=0; j < d; j++){
    	    int w;
    	    cin>>w;
    	    has_snacks[w - 1] = true;
    	}
	}
	for(int i=0;i<n;i++){
	    if(has_snacks[i]==false){
	        ans++;    
	    }
	}
	cout<<ans<<endl;
}
