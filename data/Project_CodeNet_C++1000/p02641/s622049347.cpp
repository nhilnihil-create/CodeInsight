#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define m_p make_pair
#define vi vector<int>
#define pi pair<int, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define el cout<<endl
#define sz(a) (int)a.size()
const int mod = (int)1e9+7;
typedef long long int ll;

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = (int)1e5+5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int x,n;
	cin>>x>>n;
	int ans1=1000,ans2=1000, mn1=10000, mn2=10000;
	int b[105]={0};
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		b[a]++;
	}	
	for(int i=x;i>=0;i--){
		if(b[i]==0){
			ans1 = i;
			mn1 = abs(x-i);
			break;
		}
	}
	for(int i=x+1;i<=101;i++){
		if(b[i]==0){
			ans2 = i;
			mn2 = abs(x-i);
			break;
		}
	}
	if(mn1<mn2) cout<<ans1;
	else if(mn1>mn2) cout<<ans2;
	else cout<<min(ans1,ans2);
	el;
}

ll power(ll a,ll b, ll md=mod){
	ll r=1;
	while(b){
		if(b%2) 
			r=(r*a)%md;
		a=(a*a)%md;
		b>>=1;
	}
	return r;
}