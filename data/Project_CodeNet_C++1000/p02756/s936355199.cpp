#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	deque<char>q;
	string t;cin>>t;
	for(ll i=0;i<t.size();i++){
		q.push_back(t[i]);
	}
	ll m;
	cin>>m;
	ll p=0;
	for(ll i=0;i<m;i++){
		ll now;
		cin>>now;
		if(now==2){
			ll next;char s;
			cin>>next>>s;
			next--;
			if(p==next){
				q.push_front(s);
			}
			else{
				q.push_back(s);
			}
		}
		else{
			p=abs(p-1);
		}
	}
	if(p==0){
		for(ll i=0;i<q.size();i++){
			cout << q[i];
		}
	}
	else{
		for(ll i=0;i<q.size();i++){
			cout << q[q.size()-i-1];
		}		
	}
	return 0;
}