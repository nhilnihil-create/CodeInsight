#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(0);
	
	priority_queue<ll> pq;
	string s;
	
	while(cin>>s && s!="end")
	{ 
		 ll x;

		if(s=="insert") 
		{		 cin>>x;
			
			pq.push(x);
	
			
		}
		else {
			x=pq.top();
			pq.pop();
			printf("%lld\n",x);
		}
	}
	return 0;
}