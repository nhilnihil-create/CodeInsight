#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n;
char a[10];
void dep(ll now,ll cnt){
	if(now==n){
		for(ll i=0;i<n;i++){
			cout << a[i];
		}
		cout <<endl;
		return ;
	}
	for(ll i=0;i<cnt;i++){
		a[now]='a'+i;
		if(i==cnt-1){
			dep(now+1,cnt+1);
		}
		else{
		dep(now+1,cnt);
		}
	}
}
int main() {
	cin>>n;
	dep(0,1);
	return 0;
}