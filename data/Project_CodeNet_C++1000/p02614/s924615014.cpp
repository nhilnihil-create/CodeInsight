#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	int h,w,k,ans=0;
	cin>>h>>w>>k;
	string s[h];
	for(string &i:s) cin>>i;
	int tot=0;
	for(string &i:s) for(char c:i) if(c == '#') tot++;	
	const int R=(1<<h),C=(1<<w);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int rm=0;
			for(int r=0;r<h;r++) if((1<<r) & i) for(int c=0;c<w;c++) rm+=(s[r][c] == '#');
			for(int c=0;c<w;c++) if((1<<c) & j) for(int r=0;r<h;r++) rm+=(s[r][c] == '#' && !((1<<r) & i));
			ans+=(tot-rm == k);
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
