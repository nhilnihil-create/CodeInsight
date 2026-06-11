#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	deque<pair<char, int> > dq;
	for(auto ch : s){
		if(dq.empty() || dq.back().first != ch)dq.push_back({ch, 1});
		else dq.back().second++;
	}
	for(int i = 0; i < dq.size(); i += 2){
		int r = dq[i].second;
		int l = dq[i + 1].second;
		for(int j = 1; j < r; j++){
			cout<<0<<" ";
		}
		int tot = r + l;
		if(tot&1){
			if(r&1)cout<<(tot + 1)/2<<" "<<tot/2<<" ";
			else cout<<tot/2<<" "<<(tot + 1)/2<<" ";
		}else{
			cout<<tot/2<<" "<<tot/2<<" ";
		}
		for(int j = 1; j < l; j++){
			cout<<0<<" ";
		}
	}
	cout<<'\n';

	return 0;
}