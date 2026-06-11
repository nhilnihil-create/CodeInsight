#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;

template<class T>void read(T &x){
    T s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    x = s*w;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
char s[maxn];int len;

map<int,int> mp;
void solve(){
	ll ans = 0;
	mp[0] = 1;
	int pre = 0;
	int Pow = 1;
	for(int i = len;i>=1;i--){
		pre = (pre + Pow * (s[i] -'0')%2019)%2019;
		ans += mp[pre];
		mp[pre]++;
		Pow = (Pow*10)%2019;
	}
	printf("%lld\n",ans);
}	
int main(){
	// debug;
	
	scanf("%s",s+1); len = strlen(s+1);
	solve();
	
	return 0;
}
