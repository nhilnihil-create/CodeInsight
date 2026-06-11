#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	int cnt=1;
	rep(i,n){
		if(cnt==v[i]) cnt++;
	}
	cnt--;
	if(n-cnt==n) cout<<-1<<endl;
	else cout<<n-cnt<<endl;
}