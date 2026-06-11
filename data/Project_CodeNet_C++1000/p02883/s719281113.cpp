#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL INF=1e18;

vector<LL> A, F;
int N;

LL count(LL mid){
	LL res=0;
	rep(i,N){
		LL a=mid/F[i];
		res+=max(0LL,A[i]-a);
	}
	return res;
}

bool exceed(LL mid, LL key){
	LL res=count(mid);
	if(res>key) return true;
	else return false;
}

LL binary_search(LL key){
	LL left=-1, right=INF;
	while(right-left > 1){
		LL mid=left+(right-left)/2;
		if(exceed(mid,key)) left=mid;
		else right=mid;
	}
	return right;
}

int main(){
	cin >> N;
	LL K;
	cin >> K;
	A.resize(N);
	F.resize(N);
	rep(i,N) cin >> A[i];
	rep(i,N) cin >> F[i];
	sort(A.begin(),A.end(),greater<LL>());
	sort(F.begin(),F.end());
	LL ans=binary_search(K);
	cout << ans << endl;

	return 0;
}