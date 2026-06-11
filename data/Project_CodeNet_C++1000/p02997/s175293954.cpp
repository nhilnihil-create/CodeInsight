#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

int main(){
	int n,k;
	cin>>n>>k;
	
	int hoge=(n-1)*(n-2)/2;
	if(k>hoge){
		cout<<-1<<endl;
		return 0;
	}
	
	int m=n-1+hoge-k;
	cout<<m<<endl;
	
	for(int i=2;i<=n;++i) cout<<1<<' '<<i<<endl;
	
	int cnt=0;
	int u=2;
	while(cnt<hoge-k){
		for(int v=u+1;v<=n;++v){
			cout<<u<<' '<<v<<endl;
			if(++cnt>=hoge-k) return 0;
		}
		u++;
	}
}