#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#define pb push_back
#define st first
#define nd second
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long lo;
const int mod=1000000007,N=500005;
lo a,b,c,d,e,g=1,arr[N],h[N];

void solve(){
	cin >> a;
	for(lo i=1;i<=a;i++){
		cin >> arr[i];
		h[i]=h[i-1]+arr[i];
	}
	lo x=0,ans=mod;
	for(lo i=a;i>=1;i--){
		ans=min(ans,abs(x-h[i]));
		x+=arr[i];
	}
	cout << min(ans,x) << endl;
}

int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	// cin >> g;
	while(g--) solve();
}