#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	cin >> N;
	vector<LL> A(N);
	rep(i,N) cin >> A[i];
	map<LL,LL> s, d;
	rep(i,N) s[(i+1)+A[i]]++;
	rep(i,N) d[(i+1)-A[i]]++;
	LL ans=0;
	for(auto itr:s){
		ans+=itr.second*d[itr.first];
	}
	cout << ans << endl;

	return 0;
}