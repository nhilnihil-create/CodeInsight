#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	queue<ll>ch[1010];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n-1;j++){
			ll now;
			cin>>now;
			now--;
			ch[i].push(now);
		}
	}
	queue<ll>st;
	for(ll i=0;i<n;i++){
		st.push(i);
	}
	ll ans=0;
	while(st.size()!=0){
		ll z=st.size();
		ans++;
		bool mi=false;
		map<ll,ll>sumi;
		for(ll i=0;i<z;i++){
			ll now=st.front();
			st.pop();
			if(ch[now].size()!=0){
			ll nex=ch[now].front();
			
			if(now==ch[nex].front()&&sumi[now]==0&&sumi[nex]==0){
				sumi[now]++;
				sumi[nex]++;
				ch[now].pop();
				ch[nex].pop();
				if(ch[now].size()!=0){
				st.push(now);
				}
				if(ch[nex].size()!=0){
				st.push(nex);
				}
				mi=true;
		//		cout << now<<" "<<nex<<endl;
			}
			}
		}
		if(mi!=true){
			break;
		}
	}
	for(ll i=0;i<n;i++){
		if(ch[i].size()!=0){
			cout << -1;
			return 0;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}