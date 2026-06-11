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
	rep(i,n)cin>>a[i];
	sort(all(a));
	if(a[0]==0){
		cout<<0<<endl;
		return 0;
	}
	int pro=1;
	rep(i,n){
		if(INF/pro+1<a[i]){
			cout<<-1<<endl;
			return 0;
		}
		pro*=a[i];
		
	}
	if(pro>INF) cout<<-1<<endl;
	else cout<<pro<<endl;
	return 0;
}

