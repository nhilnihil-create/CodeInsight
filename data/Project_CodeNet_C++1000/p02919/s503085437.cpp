#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) {
		cin >> p[i];
		p[i]--;
	}
	
	vector<int> idx(n);
	rep(i,n) idx[p[i]] = i;
	
	set<int> bigidx;
	ll res = 0;
	for(int i = n-1; i >= 0; i--){
		bigidx.insert(idx[i]);
		if(i==n-1) continue;
		auto itr = bigidx.find(idx[i]);
		
		
		ll l1 = 0;
		ll r1 = 0;
		ll l2 = 0;
		ll r2 = 0;
		
		// L
		auto litr = itr;
		if(litr != bigidx.begin()){
          litr--;
			l1 = idx[i] - *litr;
		}
		else{
			l1 = idx[i]+1;
			l2 = l1;
		}
		if(l1 != idx[i]+1 && litr != bigidx.begin()){
          litr--;
			l2 = idx[i] - *litr;
		}
		else l2 = idx[i]+1;
		
		// R
		auto ritr = itr;
		if(++ritr != bigidx.end()){
			r1 = *ritr - idx[i];
		}
		else{
			r1 = n - idx[i];
			r2 = r1;
		}
		if(r1 != n - idx[i] && ++ritr != bigidx.end()){
			r2 = *ritr - idx[i];
		}
		else r2 = n - idx[i];
		
		// cout << l2 << l1 << r1 << r2 << endl;
		res += ( (l1 * (r2 - r1)) + ((l2 - l1) * r1) ) * (i+1);
	}
	
	cout << res << endl;
	return 0;
}