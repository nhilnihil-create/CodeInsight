#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	
	int n,x,ans=0,d=0;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		d+=q;
		if(d<=x)ans++;
	}
	cout<<ans+1;
}