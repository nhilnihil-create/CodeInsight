
#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main(){

	ll n;
	cin >> n;

	vector<ll> p(n);
	for(ll i=0; i<n; i++){
		ll j;
		cin >> j;
		p[j-1]=i;
	}

	multiset<ll> st;

	st.insert(-1);
	st.insert(-1);
	st.insert(n);
	st.insert(n);

	ll v0,v1,v2,v3;

	ll r=0;

	for(ll i=n-1;0<=i;i--){
		ll j=p[i];
		auto it=st.lower_bound(j);
		it--;it--;
		//cout << j << endl;
		//for(auto sti: st) cout<<sti<<" ";
		//cout << *it << endl;
		v0=*it;
		it++; v1=*it;
		it++; v2=*it;
		it++; v3=*it;
		//cout << ":" << v0 << " " << v1 << " " << v2 << " " << v3 << endl;
		r+=(i+1)*(v1-v0)*(v2-j)+(i+1)*(j-v1)*(v3-v2);
		st.insert(j);

	}



	cout << r << endl;

	return 0;

}
