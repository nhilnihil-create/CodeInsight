#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long N,cnt,now,ans;
	cin>>N;
	vector<long long> H(N);
	rep(i,N) cin>>H[i];
	cnt=0;
	now=H[0];
	ans=0;
	rep(i,N-1){
		if(now<H[i+1]){
			if(ans<cnt) ans=cnt;
		  cnt=0;
		}
		else cnt++;
		now=H[i+1];
	}
	if(ans<cnt) ans=cnt;
	cout<<ans<<endl;
}