#include<bits/stdc++.h>
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef priority_queue<int> BQ;
const double eps=1e-8;
inline int sign(double x){return (x>eps)-(x<-eps);}
const int maxn=3e5+10,mod=1e9+7,INF=0x3f3f3f3f;
ll a[maxn];
char s[maxn];
ll bs[100];
void insert(ll x)
{
    for (int i=62;i>=0;--i)
    {
        if (x&(1ll<<i))
        {
            if (!bs[i])
            {
                bs[i]=x;
                return;
            }
            x^=bs[i];
        }
    }
}
inline bool check(ll x)
{
    for (int i=62;i>=0;--i)
        if (x&(1ll<<i))
            x^=bs[i];
    return x==0;
}
int main()
{
	int T;
	cin>>T;
	while (T--){
		memset(bs,0,sizeof(bs));
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		scanf("%s",s+1);
		int ans=0;
		for (int i=n;i;--i){
			if (s[i]=='0')
				insert(a[i]);
			else{
				if (!check(a[i]))
					ans=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
