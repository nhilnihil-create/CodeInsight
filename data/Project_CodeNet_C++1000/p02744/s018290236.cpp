#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n;
ll ch[12];
void dep(ll now,ll ma){
	if(now==n){
		for(ll i=0;i<n;i++){
			ll ne=ch[i];
			cout << char(ne+'a');
		}
		cout <<endl;
		return;
	}
	for(ll i=0;i<=ma+1;i++){
		ch[now]=i;
		dep(now+1,max(i,ma));
	}
}
int main() {
	cin>>n;
	ch[0]=0;
	dep(1,0);
	// your code goes here
	return 0;
}