#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 1e6 + 5;
const int N = 2e5 + 5;

char s[N];
int suf[N],cnt[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,p;cin>>n>>p>>s+1;
	int base=1;
	ll ans=0;
	if(10%p==0){
		for(int i=1;i<=n;i++){
			if((s[i]-'0')%p==0) ans+=i;
		}
	}else{
		cnt[0]++;
		for(int i=n;i>=1;i--){
			int j=s[i]-'0';
			suf[i]=(suf[i+1]+j*base)%p;
			ans+=cnt[suf[i]];
			cnt[suf[i]]++;
			base=base*10%p;
		}
	}
	cout<<ans<<'\n';
	return 0;
}