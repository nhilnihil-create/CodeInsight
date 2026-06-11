#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>a[1000];
	vector<ll>st;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n-1;j++){
			ll x;
			cin>>x;
			x--;
			a[i].push_back(x);
		}
		reverse(a[i].begin(),a[i].end());
		st.push_back(i);
	}
	ll cnt=0;
	while(st.size()!=0){
		cnt++;
		bool ok[1000];
		for(ll i=0;i<n;i++){
			ok[i]=false;
		}
//		cout <<cnt<<endl;
		while(st.size()!=0){
			ll now=st.back();
			st.pop_back();
			ll next=a[now].back();
			if(ok[now]||ok[next]){
				continue;
			}
			if(a[next].back()==now){
				ok[now]=true;
				ok[next]=true;
				a[now].pop_back();
				a[next].pop_back();
			}
		}
		for(ll i=0;i<n;i++){
		//	cout << i <<ok[i]<<endl;
			if(ok[i]==true&&a[i].size()!=0){
				st.push_back(i);
			}
		}
	}
	for(ll i=0;i<n;i++){
		if(a[i].size()){
			cout <<-1;
			return 0;
		}
	}
	cout << cnt;
	// your code goes here
	return 0;
}