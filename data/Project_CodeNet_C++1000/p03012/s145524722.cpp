#include <bits/stdc++.h>

#define ll long long
#define sz(x) (int)x.size();

using namespace std;

const int N=105;
int n;
int p[N],s[N],a[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]+=p[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		s[i]+=s[i+1]+a[i];
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		ans=min(ans,abs(s[i+1]-p[i]));
	}
	cout<<ans;

}