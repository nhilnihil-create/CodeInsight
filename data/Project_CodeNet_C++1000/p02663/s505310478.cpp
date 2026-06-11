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
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

int main(){
	int h[2],m[2];
	REP(i,2) cin>>h[i]>>m[i];
	
	int k;
	cin>>k;
	
	if(h[0]>h[1]) h[1]+=24;
	REP(i,2) m[i]+=60*h[i];
	
	cout<<m[1]-m[0]-k<<endl;
}