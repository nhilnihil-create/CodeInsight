#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

ll count(string &now){
	ll sum{};
	while(now.size()>1){
		sum++;
		int k = now.size();
		int a = (*(now.end()-1))-'0';
		int b = (*(now.end()-2))-'0';
		now.erase(now.end()-2,now.end());
		auto s = to_string(a+b);
		now += s;
	}
	return sum;
}
pair<ll,string> count(ll d, ll c){
	string s;
	ll sum{};
	while(c>1){
		if(c%2) s += to_string(d);
		d*=2;
		c/=2;
		sum += c;
		if(d>9){
			d = d/10 + d%10;
			sum += c;
		}
	}
	s += to_string(d);
	sum += count(s);
	return {sum,s};
}

int main(){
	int m; cin>>m;
	ll sum{};
	string now;
	for(int i=0; i<m; i++){
		ll d,c; cin>>d>>c;
		auto v = count(d,c);
		sum += v.first;
		now += v.second;
	}
	sum += count(now);
	
	cout << sum << endl;
}
