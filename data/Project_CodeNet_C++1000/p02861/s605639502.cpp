#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
    vector<pair<double,double>> P(n);
	rep(i,n) cin >> P[i].first >> P[i].second;
	vector<int> keiro;
	rep(i,n) keiro.push_back(i);

	double ans = 0.0;
	double sum = 0.0;
	do{
		rep(i,n-1){
			double dx = P[keiro[i+1]].first - P[keiro[i]].first;
			double dy = P[keiro[i+1]].second - P[keiro[i]].second;
			ans += sqrt(dx*dx + dy*dy);
		}
		sum++;
	}while(next_permutation(keiro.begin(),keiro.end()));
	ans /= sum;
	cout << fixed << setprecision(16) << ans << endl;
	return 0;
}