# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define mset multiset
# define umap unordered_map
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 1e6+4;

int cnt[N];

void solve(){
	int n;
	cin>>n;
	vector<int>a(n);
	int g=0;
	rep(i,n){
		cin>>a[i];
		g=__gcd(g,a[i]);
	}
	if(g>1){
		cout<<"not coprime";
		return;
	}
	sort(all(a));
	reverse(all(a));
	for(int i=0;i<n;++i){
		for(int j=2;j*j<=a[i];++j){
			if(a[i]%j==0){
				if(cnt[j]){
					cout<<"setwise coprime";
					return;
				}
				cnt[j]++;
				while(a[i]%j==0){
					a[i]/=j;
				}
			}	
		}
		if(a[i]>1){
			if(cnt[a[i]]){
				cout<<"setwise coprime";
				return;
			}
			cnt[a[i]]=1;
		}
	}
	cout<<"pairwise coprime";

}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}