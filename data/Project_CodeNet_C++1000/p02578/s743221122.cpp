#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int a[300000];
int main(){
	int n;cin>>n;
	rep(i,n)scanf("%d",&a[i]);
	ll ans=0;
	ll cur=0;
	rep(i,n){
		if(cur>a[i]){
			ans+=cur-a[i];
		}
		else cur=a[i];
	}
	cout<<ans<<endl;
}