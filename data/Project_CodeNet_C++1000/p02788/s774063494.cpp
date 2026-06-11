#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
 
int main(){
	
	ll n,d,a; cin>>n>>d>>a;
	d*=2;
	vector<pair<ll,ll>> x(n);
	for(auto &i:x) cin>>i.first>>i.second;
	deque<pair<ll,ll>> damage;
	ll cnt{};
	sort(x.begin(),x.end());
	ll sum{};
	for(int i=0; i<n; i++){
		while(!damage.empty()){
			auto p = damage.front();
			if(x.at(i).first-p.first>d){
				sum -= damage.front().second*a;
				damage.pop_front();
			}
			else break;
		}
		if(x.at(i).second<=sum) continue;
		damage.push_back({x.at(i).first,(x.at(i).second-sum+a-1)/a});
		cnt += (x.at(i).second-sum+a-1)/a;
		sum += (x.at(i).second-sum+a-1)/a*a;
	}
	
	cout << cnt << endl;
}
