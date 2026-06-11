#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string u;
	cin>>u;
	deque<char>q;
	for(ll i=0;i<u.size();i++){
		q.push_back(u[i]);
	}
	ll re=0;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		if(now==1){
			re=abs(re-1);
		}
		else{
			ll ne;
			cin>>ne;
			ne--;
			ne=abs(ne-re);
			char t;
			cin>>t;
			if(ne==0){
				q.push_front(t);
			}
			else{
				q.push_back(t);
			}
		}
	}
	if(re==0){
		for(auto itr=q.begin();itr!=q.end();itr++){
			cout << *itr;
		}
	}
	else{
		for(auto itr=q.end()-1;itr!=q.begin()-1;itr--){
			cout << *itr;
		}		
	}
	// your code goes here
	return 0;
}