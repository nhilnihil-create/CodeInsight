#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N;

int main(){
	cin >> N;
	
	vector<pii> v(N);
	
	for ( int i = 0; i < N; i++ ){
		ll a, b;
		cin >> a >> b;
		v[i] = {a,b};
	}
	
	sort(v.begin(), v.end(), [](const pii &l, const pii &r){return l.second < r.second;});
	
	int tsum = 0;
	for ( int i = 0; i < N; i++ ){
		tsum += v[i].first;
		if ( tsum > v[i].second ){
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	
	
	return 0;
}

