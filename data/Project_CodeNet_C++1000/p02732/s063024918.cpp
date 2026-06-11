#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using p = pair<int,int>;
const LL MX = 2000000;

int main(){
	int N;cin >> N;
	vector<LL> A(N);
	vector<LL> cnt(MX);
	rep(i,N){
		int tmp;cin>>tmp;
		A[i] = tmp;
		++cnt[tmp];
	}
	
	LL res = 0;
	rep(j,MX){
		if(cnt[j]>=2) res += cnt[j]*(cnt[j]-1)/2;
	}


	rep(i,N){
		LL ans = res;
		if(cnt[A[i]]>=2){
			ans -= cnt[A[i]]*(cnt[A[i]]-1)/2;
			ans += (cnt[A[i]]-1)*(cnt[A[i]]-2)/2;
		}
		cout << ans << endl;
	}

}

