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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,m;
set<int> st;

bool f(int x){
	return st.find(x)==st.end();
}	

int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	if(f(m)) cout<<m<<endl;
	else{
		for(int i=1;;i++){
			if(f(m-i)){
				cout<<m-i<<endl;
				break;
			}
			if(f(m+i)){
				cout<<m+i<<endl;
				break;
			}
		}
	}
}