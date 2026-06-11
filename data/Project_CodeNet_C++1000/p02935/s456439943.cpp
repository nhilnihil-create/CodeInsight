#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	cin >> N;
	vector<int> v(N);
	rep(i,N) cin >> v[i];
	sort(v.begin(),v.end());
	double ans=v[0];
	rep(i,N-1){
		ans+=v[i+1];
		ans/=2;
	}
	cout << setprecision(15) << ans << endl;

	return 0;
}