#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int a[2000000];
int b[2000000];
int main(){
	int n;cin>>n;
	rep(i,n)scanf("%1d",&a[i]);
	set<int>se;
	rep(i,n-1){
		b[i]=abs(a[i]-a[i+1]);
		se.insert(b[i]);
	}
	n--;
	bool flag=false;
	if(se.count(1)){
		rep(i,n)b[i]%=2;
	}
	else{
		flag=true;
		rep(i,n)b[i]/=2;
	}
	int ans=0;
	rep(i,n){
		if(n-1==(i|(n-1-i)))ans^=b[i];
	}
	if(flag)ans*=2;
	cout<<ans<<endl;
}