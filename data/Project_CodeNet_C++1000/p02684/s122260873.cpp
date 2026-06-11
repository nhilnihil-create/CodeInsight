#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define mp make_pair
#define pb push_back
void solve(){
	ll n,k;
	cin>>n>>k;
	int a[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	int steps[n+1]={0};
	int cur=1;
	ll i=1;
	for(;i<=k;i++){
		cur=a[cur];
		if(!steps[cur])
			steps[cur]=i;
		else
			break;
	}
	
	if(i<=k){
		int cyc=(k-steps[cur])%(i-steps[cur]);
		for(int j=1;j<=cyc;j++){
			cur=a[cur];
		}
		cout<<cur<<endl;
	}
	else
		cout<<cur<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}

