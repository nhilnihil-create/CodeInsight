#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define VI vector<int>
#define PII pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x){return mrand()%x;}
clock_t ac; double TLE(){return (double)(clock()-ac)/CLOCKS_PER_SEC;}
void DBG() {cerr << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
cerr << to_string(h);
if(sizeof...(t)) cerr << ", ";
DBG(t...);}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 int n,k;
 //int a[]={1,7,5,6,8,2,6,5};
 cin>>n>>k;
 int a[n];
 rep(i,0,n)cin>>a[i];
 int s=0;
 for(int i=0;i<n;i++)s+=a[i];
// DBG(s);
 VI d;
 for(int i=1;i*i<=s;i++){
    if(s%i==0){
	  d.pb(i);
	  d.pb(s/i);
	}
 }
// for(int x:d)DBG(x);
 // 8 7
 // 1 7 5 6 8 2 6 5
 // we factorize sum of all elements f array
 int res=1;
 for(int x:d){
    VI b(n);
	for(int i=0;i<n;i++){
	   b[i] = a[i]%x;
	}
	sort(all(b));
	int i=0;
	int j=n-1;
	ll c=0;
	//for(int u:b)DBG(u);
	while(i<j){
	  if(b[i]==0)i++;
	  else if(b[j]==x)j--;
	  else{
	    int q = min(b[i],x-b[j]);
		b[i]-=q;
		b[j]+=q;
		c+=q;
	  }
	}
	if(c<=k){
	 res = max(res,x);
	}
 }
 cout<<res<<"\n";
 return 0;

}


