#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=a;i--)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define de(x) cout << #x << "=" << x << endl
#define dd(x) cout << #x << "=" << x << " "
#define pw(x) (1ll<<(x))
#define pq priority_queue
#define endl "\n"
const ll maxn=1e5+100;
ll a[maxn],b[maxn];
int main()
{
    ios::sync_with_stdio(false);
    ll A,B,M,minn1=maxn,minn2=maxn;
    cin >> A >> B >> M;
    for(int i=1;i<=A;i++){
    	cin>> a[i];
    	minn1=min(minn1,a[i]);
	}
	for(int i=1;i<=B;i++){
		cin >> b[i];
		minn2=min(minn2,b[i]);
	}
	ll ans=minn1+minn2;
	for(int i=0;i<M;i++){
		ll x,y,c;
		cin >> x >> y >> c;
		ans=min(ans,a[x]+b[y]-c);
	}
	cout << ans << endl;
    return 0;
}
