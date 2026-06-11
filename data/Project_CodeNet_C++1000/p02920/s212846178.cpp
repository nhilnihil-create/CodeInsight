#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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
typedef pair<ll,pll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
multiset<int> st,a;

int main(){
	cin>>n;
	int N=1<<n;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	auto it=st.end();it--;
	a.insert(*it);
	for(int i=0;i<n;i++){
		vi b;
		for(auto j=a.begin();j!=a.end();j++){
			int x=*j;
			it=st.lower_bound(x);
			if(it==st.begin()){
				cout<<"No"<<endl;
				return 0;
			}
			it--;
			b.push_back(*it);
			st.erase(it);
		}
		for(auto j:b) a.insert(j);
	}
	cout<<"Yes"<<endl;
}