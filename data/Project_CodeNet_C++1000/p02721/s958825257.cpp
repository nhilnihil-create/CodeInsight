#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<random>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;



// /////////////////////////////////////////////

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// ////////////////////////////////

#define int long long
const int mod = 1e9 + 7;
int power(int a , int n){

	int res = 1;
	while(n > 0){
		res*=a;
		--n;
	}

	return res;
}
void solve(){

	int n , k , c;
	cin>>n>>k>>c;

	string s;
	cin>>s;

	int left[n+1] , right[n+1];

	memset(left , 0 , sizeof left);
	memset(right , 0 , sizeof right);
	int job = 0;
	for(int i = 0 ; i < n ; ++i){

		if(s[i]=='x')
			continue;

		int j = i;
		++job;
		left[i] = job;
		if(job==k)
			break;
		i+=c;
	}

	reverse(s.begin(),s.end());
	job = k;
	for(int i = 0 ; i < n ; ++i){

		if(s[i]=='x')
			continue;

		int j = i;
		///++job;
		right[n-i-1] = job--;
		if(job==0)
			break;
		i+=c;
	}

	for(int i = 0 ; i < n ; ++i){

		if(left[i]==right[i] && left[i]!=0){

			cout<<i+1<<endl;
		}
		//debug(i , left[i] , right[i]);
	}
}

signed main(){

    fast;
    int t = 1;
    //cin>>t;
    for(int i = 1 ; i <= t ; ++i){

    	solve();
    	
    	//cout<<"Case #"<<i<<": ";
    }
}
