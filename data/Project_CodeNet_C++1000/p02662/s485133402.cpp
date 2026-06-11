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

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x;
while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {
cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

const int M = 998244353;
const ll  Inf = (ll)2e18 + 5;
const int N   = 2e3 + 5;
ll vis[N],res[N];
int dp[N];

void add(int& x, int y){
	x += y;
	if(x>=M) x -= M;
}

int solve() 
{
  //happy coding


	int n,m;
	cin>>n>>m;

	std::vector<int> a(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	ll inv2 = (M+1)/2;

	dp[0] = 1;

	for(int i=0;i<n;i++)dp[0] = dp[0]*2%M;

	/*for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;*/

	for(int i=0;i<n;++i){
		for(int j=m;j>=a[i];--j){
			//cout<<dp[j-a[i]]<<endl;
			add(dp[j],dp[j-a[i]]*inv2 % M);
		}
	}

	/*for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;*/

	cout<<dp[m]<<endl;
  

  
  return 0;
}
int main(){
  int test = 1;
  //scanf("%d", &test);
  while (test--)solve();return 0;
}