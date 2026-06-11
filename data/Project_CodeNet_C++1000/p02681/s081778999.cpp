#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
int main(){
	string s,t;
	cin>>s>>t;
	bool flag=1;
	rep(i,s.size()){
		if(s[i]!=t[i])flag=0;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}