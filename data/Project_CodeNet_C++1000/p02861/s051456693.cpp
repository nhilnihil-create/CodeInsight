#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	cout<<fixed<<setprecision(10);
	double n; cin>>n;
	vector< int > v;
	vector< pair< double, double > > pa(n);
	double ans = 0, divide = 0;
	for(int i = 0; i<n; i++){
		v.push_back(i);
		cin>>pa[i].first>>pa[i].second;
	}
	do{
		for(int i = 1; i<n; i++){
			ans += sqrt(((pa[v[i]].first - pa[v[i - 1]].first) * (pa[v[i]].first - pa[v[i - 1]].first)) + ((pa[v[i]].second - pa[v[i - 1]].second) * (pa[v[i]].second - pa[v[i - 1]].second)));
		}
		divide += 1;
	}while(next_permutation(v.begin(), v.end()));
	cout<<(ans / divide)<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
