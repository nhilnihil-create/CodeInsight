#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
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
bool isprime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

signed main(){
	int n,k,r,s,p;
	string t;
	cin>>n>>k>>r>>s>>p>>t;

	int ans=0;

	for(int i=0;i<k;i++){
		char tmp='7';
		int f=0;
		for(int j=i;j<n;j+=k){
			// cout<<j<<' '<<ans<<endl;

			if(tmp==t[j]){
				f=1-f;
				tmp=t[j];
				if(f)continue;
			}else{
				f=0;
			}
			
			if(t[j]=='r') ans+=p;
			else if(t[j]=='s') ans+=r;
			else if(t[j]=='p') ans+=s;

			tmp=t[j];
			
		}
	}
	cout<<ans<<endl;



	return 0;
}

