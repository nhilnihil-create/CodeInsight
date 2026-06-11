#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(s) s.begin(),s.end()
#define vll vector<ll>
#define vi vector<int>
#define vpii vector<pii>
#define vpll vector<pll>
#define vull vector<ull>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define sz(x) x.size()
#define cinarr(n,a) for(int i = 0; i < n; i++) cin >> a[i];
#define coutarr(n,a) for(int i = 0; i < n; i++) cout << a[i] << (i+1==n?'\n':' ');
#define fori(i,a,b,x) for(int i = a; i <= b; i+=x)
#define ford(i,a,b,x) for(int i = a; i >= b; i-=x)
#define tc int tt; scanf("%d",&tt); for(int cs = 1; cs <= tt; cs++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define reset(x,y) memset(x,y,sizeof x);
#define EPS 1e-10
#define INF 2000000000
#define mod 1000000007
#define debug(val) cerr << "The value of " << #val << " is = " << val << endl;
#define testing cerr << "--------------------------\n";
vi ada(200005,0);
int ans=-1;
int main() { 
	IOS
	int n;
	cin>>n;
	ada[0]=1;
	for(int i = 0,x; i < n; i++) {
		cin>>x;
		ada[x]=ada[x-1];
		if(ada[x]) {
			ans=max(ans,x);
		}
	}
	if(ans==-1) {
		cout<<"-1\n";
	} else {
		cout<<n-ans<<endl;
	}
}
