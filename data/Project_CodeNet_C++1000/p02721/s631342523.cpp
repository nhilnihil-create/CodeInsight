#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define d1(x)  cerr << #x << "--> " << x << endl
#define d2(x,y)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<endl
#define d3(x,y,z)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z<< endl
#define d4(x,y,z,w)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z << " | "<< #w << "--> " << w <<endl
#define vpll vector<pair<ll,ll>>
#define F first
#define S second
#define T ll tt; cin>>tt; while(tt--)
using namespace std;
ll mode=1ll<<32;
const ll maxn=1e3+10;
ll __lcm(ll a, ll b){ return (a*b)/__gcd(a,b); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRand(ll l, ll r){ uniform_int_distribution<int> uid(l, r); return uid(rng); }


void solve(){
	
	ll n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	s="%"+s;
	ll pre[n+1];
	pre[0]=0;
	for (int i=1;i<=n;){
		if (s[i]=='o'){
			pre[i]=pre[i-1]+1;
			for (int j=1;j<=c;j++){
				if (i+j<=n) pre[i+j]=pre[i];
			}
			i=i+c+1;
		}
		else{
			pre[i]=pre[i-1];
			i++;
		}
	}
	ll suf[n+2];
	suf[n+1]=0;
	for (int i=n;i>=1;){
		if (s[i]=='o'){
			suf[i]=suf[i+1]+1;
			for (int j=1;j<=c;j++){
				if ((i-j)>=1) suf[i-j]=suf[i];
			}
			i=i-c-1;
		}
		else{
			suf[i]=suf[i+1];
			i--;
		}
	}
	
	for (int i=1;i<=n;i++){
		if ((pre[i-1]+suf[i+1])>=k){
			
		}
		else{
			cout<<i<<endl;
		}
	}
	
	return;
	
}

int main(){ 
    
    #ifndef ONLINE_JUDGE
  	//	freopen("input.txt", "r", stdin);
    #endif
    srand(time(0)); 
    
    ios::sync_with_stdio(0);
    cin.tie(0);


	//T{ solve(); }
	solve();
		
	
	return 0;
}