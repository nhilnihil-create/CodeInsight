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
	int h,w,k;
	cin>>h>>w>>k;
	char c[7][7];
	rep(i,h)rep(j,w){
		cin>>c[i][j];
	}
	int ans=0;
	vi x(h,0),y(w,0);
	int sum=0;
	rep(i,h){
		rep(j,w){
			if(c[i][j]=='#'){
				x[i]++;
				y[j]++;
				sum++;
			}

		}
	}

	rep(bit,1<<(h+w)){
		int cnt=sum;
		vector<int> visit(h,0);
		rep(i,h){
			if(bit&(1<<i)){
				cnt-=x[i];
				visit[i]=1;
			}
		}
		rep(j,w){
			if(bit&(1<<(h+j))){
				cnt-=y[j];
				rep(i,h){
					if(visit[i]&&c[i][j]=='#'){
						cnt++;
					}
				}
			}
		}
		if(cnt==k) ans++;



	}
	cout<<ans<<endl;


	return 0;
}

