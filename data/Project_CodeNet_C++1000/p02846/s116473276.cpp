#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void line(const Type &a){int cnt=0;for(auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

//Referin to exp.
int main(){
	llong t[2],a[2],b[2];
	REP(i,2) cin>>t[i];
	REP(i,2) cin>>a[i];
	REP(i,2) cin>>b[i];
	
	llong p[2];
	if(a[0]<b[0]) swap(a,b);
	REP(i,2) p[i]=(a[i]-b[i])*t[i];
	
	if(p[0]+p[1]==0){
		cout<<"infinity"<<endl;
		return 0;
	}else if(p[0]+p[1]>0){
		cout<<0<<endl;
		return 0;
	}
	
	llong cnt=p[0]/abs(p[0]+p[1]);
	if(p[0]%abs(p[0]+p[1])) cnt=cnt*2+1;
	else cnt*=2;
	
	cout<<cnt<<endl;
}
