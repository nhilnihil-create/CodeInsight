#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define check system("pause")
#define all(x) (x).begin(),(x).end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
const int N = 2e5+20;
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mes(p,b) memset(p,b,sizeof(p))
#define sz(x) int(x.size())
ll b[N],a[N],n;
int main()
{
  	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	rep(i,0,n) cin>>a[i];
	dep(i,n,0) b[i]=b[i+1]+a[i];
	ll lim=1,ans=0;
	rep(i,0,n){
		lim=min(lim,b[i]);
		ans+=lim;
		lim-=a[i];
		if(lim<0){
			cout<<-1;return 0;
		}
		lim<<=1;
	}
	cout<<ans;
  	return 0;
}

