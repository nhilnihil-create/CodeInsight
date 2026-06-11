#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int N;
vector<ll> A;

int main() {
	cin>>N;
	A.resize(N);
	rep(i,N) cin>>A[i];
	vector<ll> plus,minus;
	rep(i,N){
		if(A[i]>=0) plus.push_back(A[i]);
		else minus.push_back(A[i]);
	}
	sort(all(plus),greater<ll>());
	sort(all(minus));
	if(minus.empty()) minus.push_back(plus.back()), plus.pop_back();
	if(plus.empty()) plus.push_back(minus.back()), minus.pop_back();

	vector<pair<ll,ll>> res;
	ll cur=minus[0];
	for(int i=0;i+1<plus.size();i++){
		res.push_back({cur,plus[i]});
		cur-=plus[i];
	}
	res.push_back({plus.back(),cur});
	cur=plus.back()-cur;

	for(int i=1;i<minus.size();i++){
		res.push_back({cur,minus[i]});
		cur-=minus[i];
	}
	cout<<cur<<endl;
	for(auto p : res) cout<<p.first<<" "<<p.second<<endl;
}