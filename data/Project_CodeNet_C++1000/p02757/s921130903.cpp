#include <bits/stdc++.h>
#define ls x<<1
#define rs x<<1|1
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define fun function
#define sz(x) (x).size()
#define lowbit(x) (x)&(-x)
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long
namespace FastIO {
#define BUF_SIZE 100000
#define OUT_SIZE 100000
	bool IOerror=0;
	inline char nc() {
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend) {
			p1=buf;
			pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1) {
				IOerror=1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
	}
	template<class T> inline bool read(T &x) {
		bool sign=0;
		char ch=nc();
		x=0;
		for(; blank(ch); ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	template<class T,class... U>bool read(T& h,U&... t) {
		return read(h)&&read(t...);
	}
#undef OUT_SIZE
#undef BUF_SIZE
};
using namespace std;
using namespace FastIO;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const int N=1e6+10;

int cnt[N];

signed main() {
	
#ifdef xiaofan
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif

	string s;
	int n,p,ans=0;
	cin>>n>>p>>s;
	if(p==2||p==5) {
		for(int i=0; i<n; i++)
			if((s[i]-'0')%p==0) ans+=i+1;
	} else {
		int t=1,sum=0;
		cnt[0]=1;
		for(int i=n-1; i>=0; i--) {
			sum=(sum+(s[i]-'0')*t)%p;
			ans+=cnt[sum];
			cnt[sum]++;
			t=t*10%p;
		}
	}
	cout<<ans<<endl;



	return 0;
}
