#include <bits/stdc++.h>
#define int long long
using namespace std;
const int pri=998244353;

signed main(){
	int H,W,N; cin>>H>>W>>N;
	if(H>W)swap(H,W);
	int ans=0;
	while(N>0){
		N-=W;
		H--;
		ans++;
	}
	cout<<ans<<endl;
}