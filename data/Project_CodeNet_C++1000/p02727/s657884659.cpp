//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj
#include<bits/stdc++.h>
using namespace std;int tc = 1;
#define happy ios::sync_with_stdio(false);
#define coding  cin.tie(0);
#define F first
#define S second
#define mp make_pair
#define ll long long
#define Pi atan(1)*4
#define pb  push_back
#define vpr vector<pr> 
#define pr pair<int, int> 
#define vi std::vector<int>
#define vll std::vector<ll>
#define YES printf("YES\n");
#define NO printf("NO\n");
#define Yes printf("Yes\n");
#define No printf("No\n");
#define all(n) n.begin(),n.end()
#define point(x) setprecision(x)
#define Test printf("Case %d: ",tc++);
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define vout(v) for (auto z: v) cout << z << " "; cout << endl;

const int M = 1e9 + 7;
const ll  Inf = (ll)2e18 + 5;
const int N   = 2e5 + 5;
ll vis[N],res[N];
ll aa[N],bb[N],cc[N];

int solve() 
{
	//happy coding

	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;

	for(int i=0;i<a;i++)cin>>aa[i];
	for(int i=0;i<b;i++)cin>>bb[i];
	for(int i=0;i<c;i++)cin>>cc[i];


	sort(aa,aa+a);
	sort(bb,bb+b);
	sort(cc,cc+c);
	int h = x;
	vi v;
	for(int i=a-1;i>=0;i--){
		if(h-->0){
			v.pb(aa[i]);
		}
	}
	h = y;
	for(int i=b-1;i>=0;i--){
		if(h-->0){
			v.pb(bb[i]);
		}
	}
	sort(all(v));
	int x1 = v.size()-1;
	int c1 = c-1,v1 = x1;
	int d = x+y;
	ll sum = 0;
	while(d--){

		if(cc[c1]>v[v1]){
			sum += (ll)cc[c1];
			c1--;
		}else if(cc[c1]<=v[v1]){
			sum+=(ll)v[v1];
			v1--;
		}

	}




	//vout(v);
		cout<<sum<<endl;
	
	return 0;
}
int main(){
	int test = 1;
	//scanf("%d", &test);
	while (test--)solve();return 0;
}