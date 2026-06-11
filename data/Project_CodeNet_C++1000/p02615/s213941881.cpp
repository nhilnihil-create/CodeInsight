#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18;

/*--------------------------------------------------------------------*/

signed main(){
	int n;cin>>n;
	vi a(n);
	rep(i,n) cin>>a[i];

	sort(all(a));
	reverse(all(a));

	if(n==2){
		cout<<a[0]<<endl;
		return 0;
	}

	queue<int> q;
	q.push(a[1]);
	q.push(a[1]);

	int ans=a[0];
	FOR(i,2,n-1){
		int p=q.front();q.pop();
		ans+=p;
		q.push(a[i]);
		q.push(a[i]);
	}


	cout<<ans<<endl;

	return 0;
}

