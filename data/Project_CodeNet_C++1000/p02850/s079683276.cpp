#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
void func(int at,int forb, vector<pair<int, pair<int, int>>> &edge, vector<vector<pair<int, int>>> &path){
	int res=1;
	repi(itr,path[at]){
		if(res==forb){
			res++;
		}
		if(edge[itr->F].F!=-1){
			continue;
		}
		edge[itr->F].F=res;
		res++;
		func(itr->S,res-1,edge,path);
	}
}

	int main()
{
	int n;
	cin >>n;
	vector<vector<pair<int,int>>>path(n);
	vector<pair<int,pair<int,int>>>edge(n-1);
	int a,b;
	int k=0;
	rep(i,n-1){
		cin>>a>>b;
		a--;
		b--;
		edge[i]=mp(-1,mp(a,b));
		path[a].emplace_back(i,b);
		path[b].emplace_back(i, a);
	}
	rep(i,n){
		chmax(k,(int)path[i].size());
	}	
	cout<<k<<endl;
	func(0,-1,edge,path);
	rep(i,n-1){
		cout<<edge[i].F<<endl;
	}
}