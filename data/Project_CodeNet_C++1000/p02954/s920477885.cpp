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

const int M = 1e9 + 7;
const ll  Inf = (ll)2e18 + 5;
const int N   = 2e5 + 5;
ll vis[N],res[N];
int dp[N];
int solve() 
{
	//happy coding

	string s;
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='R'&&s[i+1]=='L'){
			int st = i;
			int en = i+1;
			int cnt = 0;
			while(st>=0){
				if(s[st]=='R'){
					cnt++;
				}else break;
				st--;
			}
			dp[i] = cnt;
			cnt = 0;
			while(en<n){
				if(s[en]=='L'){
					cnt++;
				}else break;
				en++;
			}
			dp[i+1]=  cnt;
		}
	}

	for(int i=0;i<n;){
		if(dp[i]!=0&&dp[i+1]!=0){
			int x = dp[i];
			int y = dp[i+1];
			dp[i+1] = (x-((x-1)/2))+(y-1)/2;
			dp[i] = (y-((y-1)/2))+(x-1)/2;
			i+=2;
		}else i++;
	}

	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}cout<<endl;


	
	return 0;
}
int main(){
	int test = 1;
  	//scanf("%d", &test);
  	while (test--)solve();return 0;
}