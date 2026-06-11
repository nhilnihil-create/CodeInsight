//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj
#include<bits/stdc++.h>
using namespace std;
//int input........
template <typename T> inline void readline(T &n) {n = 0; int f = 1; register int ch = getchar();
 for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;for (; isdigit(ch); 
ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';n = n * f;}
template <typename T, typename TT> inline void readline(T &n, TT &m) { readline(n); readline(m); }
template <typename T, typename TT, typename TTT> inline void readline(T &n, TT &m, TTT &l) { readline(n, m); readline(l);}
// long long input........
template <typename T> inline void readlinel(T &n) {n = 0; long long f = 1; register long long ch = getchar();
 for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;for (; isdigit(ch); 
ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';n = n * f;}
template <typename T, typename TT> inline void readlinel(T &n, TT &m) { readlinel(n); readlinel(m); }
template <typename T, typename TT, typename TTT> inline void readlinel(T &n, TT &m, TTT &l) { readlinel(n, m); readlinel(l);}
//debug..........
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x;
while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {
cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}
//............ignore it..................//
int dx[8]= {1,0,-1,0,-1,-1,1,1};int dy[8]= {0,1,0,-1,-1,1,-1,1}; int tc = 1;
#define F first
#define S second
#define pb  push_back
#define mp make_pair
#define Pi atan(1)*4
#define ll  long long int
#define happy cin.tie(0);
#define point(x) setprecision(x)
#define coding ios::sync_with_stdio(false);
#define Test printf("Case %d: ",tc++);
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define vout(v) for (auto z: v) cout << z << " "; cout << endl;
void print(int n){printf("%d ", n);}
void print(int n,int m){printf("%d ",n);printf("%d ",m);}
void print(int n,int m,int k){printf("%d ",n);printf("%d ",m);printf("%d ",k);}
void print(ll n){printf("%I64d ", n);}
void print(ll n,ll m){printf("%I64d ",n);printf("%I64d ",m);}
void print(ll n,ll m,ll k){printf("%I64d ",n);printf("%I64d ",m);printf("%I64d ",k);}
int length(long long x){int l = 0;for(long long i=x;i;i/=10)l++;return l;}
int length(string s){return s.size();}

#define   pr 	pair<int, int> 
#define   vpr 	vector<pr> 
#define   vi   	std::vector<int>
#define   vll  	std::vector<ll>
#define   all(n) n.begin(),n.end()

const int M           	= 1e9 + 7;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 4e5 + 5;
const int N1            = 1e5 + 5;

vector<pair<int,int>>adj[N1];
int color[N1];

void dfs(int u,int parent, int up){
	int c = 1;
	for(auto& it : adj[u]){
		int k = it.second , v  = it.first;
		if(v == parent )continue;
		if(c == up)++c;
		color[k] = c;
		dfs(v,u,c);
		++c;
	}
}

int solve() 
{
	//happy coding

	int n;
	readline(n);
	for(int i=0;i<n-1;i++){
		int x,y;
		readline(x,y);
		--x;--y;
		adj[x].push_back({y,i});
		adj[y].push_back({x,i});
	}

	dfs(0,-1,0);

	int maxd = 0;
	for(int i=0;i<n;i++){
		maxd = max(maxd, (int)adj[i].size());
	}
	print(maxd);
	printf("\n");

	for(int i=0;i<n-1;i++){
		print(color[i]);
		printf("\n");
	}
	


	return 0;
	//error();
}
int main(){
	int test = 1;
	//readline(test);//(void)getchar();
	while (test--)solve();return 0;
}