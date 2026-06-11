#include <bits/stdc++.h>
using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l,r,d; cin>>l>>r>>d;
	int ans=0;
	for(int i=l;i<=r;i++){
		if(i%d==0){
			ans++;
		}
	}
	cout<<ans;
}