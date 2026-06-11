#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
	std::vector<int> pre(maxn),cnt(maxn);
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++) cin>>pre[i],cnt[pre[i]]++;
	for(int i=1;i<=n;i++) {
		bool ok=1;
		for(int j=1;j*j<=pre[i];j++) {
			if(pre[i]%j==0) {
				if(j==pre[i]) {
					if(cnt[j]>1) ok=0;
				}else {
					if(cnt[j]) ok=0;
				}
				if(pre[i]/j==pre[i]) {
					if(cnt[pre[i]/j]>1) ok=0;
				}else {
					if(cnt[pre[i]/j]) ok=0;
				}
			}
		}
		if(ok) ans++;
	}
	cout<<ans<<endl;
    return 0;
}