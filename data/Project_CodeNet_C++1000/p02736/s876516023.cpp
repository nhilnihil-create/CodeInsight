#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

// 012
//0012
//1101
//2210

int n;

int main(){
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	while(1){
		if(a.size()==1) break;
		vi b(n-1);
		int mx=0;
		for(int i=0;i<n-1;i++){
			b[i]=abs(a[i]-a[i+1]);
			mx=max(mx,b[i]);
		}
		a=b;
		n--;
		if(mx<=2) break;
	}
	if(n==1) cout<<a[0]<<endl;
	else{
		int t1=0,t2=0;
		bool flag=0;
		for(int i=0;i<n;i++) if(a[i]){
			int x=n-1,y=i,B=1;
			while(x){
				if(x%2<y%2) B=0;
				x/=2;
				y/=2;
			}
			if(a[i]==1) (t1+=B)%=2,flag=1;
			else (t2+=B)%=2;
		}
		cout<<(flag?t1:t2*2)<<endl;
	}
}