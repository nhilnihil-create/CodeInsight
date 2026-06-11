#include<bits/stdc++.h>
using namespace std;
int a[25];
int b[25];
int c[25];

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) cin>>b[i];
	for(int i=1; i<n; i++) cin>>c[i];
	int last = -1;
	int curr;
	int ret = 0;
	for(int i=1; i<=n; i++){
		curr = a[i];
		ret+=b[curr];
		if(last+1==curr) ret+=c[last];
		last = curr;
	}	
	cout<<ret;
}