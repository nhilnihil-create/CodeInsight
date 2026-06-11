#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;

int main(){
	string s, t;
	cin >> s >> t;
	s+=s;
	LL ans=0, prev=-1;
	vector<vector<LL>> chara(26);
	rep(i,s.size()){
		int c=s[i]-'a';
		chara[c].emplace_back(i);
	}
	rep(i,t.size()){
		int c=t[i]-'a';
		auto itr=upper_bound(chara[c].begin(),chara[c].end(),prev);
		if(itr==chara[c].end()){
			cout << -1 << endl;
			return 0;
		}
		LL num=*itr;
		ans+=num-prev;
		if(num>=s.size()/2) prev=num-s.size()/2;
		else prev=num;
	}
	cout << ans << endl;

	return 0;
}