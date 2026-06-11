#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
string s;
ll ans,n,a[3];
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='R')a[0]++;
		else if(s[i]=='G')a[1]++;
		else a[2]++;
	} 
	ans=a[0]*a[1]*a[2];
	for(int i=0;i<n-1;i++)
		for(int d=1;i+2*d<n;d++)
			if((s[i]^s[i+d]^s[i+2*d])==('R'^'G'^'B'))ans--;
	cout<<ans<<endl;
	return 0;
}