#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int h,w,n;cin>>h>>w>>n;
	int ans=0;
	ans += n/max(h,w);
	if(n%max(h,w)!=0){
		ans++;
	}
	cout<<ans<<endl;
} 