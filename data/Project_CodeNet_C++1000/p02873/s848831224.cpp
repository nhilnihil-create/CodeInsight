#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
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
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	string s;
	cin>>s;
	int n=s.size()+1;

	vi a;
	if(s[0]=='>'){
		a.pb(0);
	}

	int tmp=1;
	rep(i,n-2){
		if(s[i]==s[i+1]) tmp++;
		else{
			a.pb(tmp);
			tmp=1;
		}
	}
	a.pb(tmp);
	if(a.size()%2==1) a.pb(0);



	int ans=0;

	rep(i,a.size()/2){
		int ma=max(a[2*i],a[2*i+1]);
		int mi=min(a[2*i],a[2*i+1]);

		ans+=ma*(ma+1)/2;
		if(mi>0) ans+=mi*(mi-1)/2;
	}
	cout<<ans<<endl;

	// rep(i,a.size()){
	// 	cout<<' '<<a[i];
	// }
	// cout<<endl;


	return 0;
}
