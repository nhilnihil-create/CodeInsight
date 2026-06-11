#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define u(x, a, b) for(ll x = a; x < b; x++)
#define d(x, a, b) for(ll x = a; x > b; x--)

typedef long long ll;
typedef long double ld;

#define MAXI 100010
#define MOD 1000000007

int main(){
	string s;
	
	ll q;
	
	cin >> s >> q;
	
	deque<char> c;
	u(one, 0, s.size()){c.push_back(s[one]);}
	
	ll cdir = 1;
	u(one, 0, q){
		ll cs;
		cin >> cs;
		
		if(cs == 1){cdir*=(-1);}
		else{
			ll f;
			char ci;
			cin >> f >> ci;
			
			if(f==1 && cdir==1){
				c.push_front(ci);
			}
			else if(f==1 && cdir==-1){
				c.push_back(ci);
			}
			else if(f==2 && cdir==1){
				c.push_back(ci);
			}
			else if(f==2 && cdir==-1){
				c.push_front(ci);
			}
			
			
			
		}
	}
	
	if(cdir==1){
		u(one, 0, c.size()){cout << c[one];}
	}
	else{
		d(one, c.size()-1, -1){cout << c[one];}
	}
}
