# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 2e5+5;

void solve(){
	int h,w,k;
	cin>>h>>w>>k;
	char c[h][w];
	rep(i,h){
		rep(j,w){
			cin>>c[i][j];
		}
	}
	int ans=0;
	rep(mask1,1<<h){
		rep(mask2,1<<w){
			int cnt=0;
			rep(i,h){
				rep(j,w){
					if(mask1&(1<<i) || mask2&(1<<j))continue;
					cnt+=c[i][j]=='#';
				}
			}
			ans+=cnt==k;
		}
	}
	cout<<ans;
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}
