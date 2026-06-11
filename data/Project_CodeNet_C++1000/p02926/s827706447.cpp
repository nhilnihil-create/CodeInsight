#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long inf=1e9;
const double pi = 3.1415926535897932384626433832795;
int main(){
	int N; cin>>N;
	deque<pair<double,pair<long,long>>> vp;
	rep(i,0,N){
		long x,y; cin>>x>>y;
		if(x == 0 && y == 0) continue;
		vp.push_back({atan2(y, x), {x, y}});
	}sort(vp.begin(), vp.end());
	int n = vp.size();
	rep(i,0,n){
		vp.push_back(vp[i]);
		vp.back().first += 2 * pi;
	}
	long ans = 0;
	rep(i,0,vp.size()){
		long x = 0, y = 0;
		rep(j,i,vp.size()){
			if(vp[j].first <= vp[i].first + pi){
				x += vp[j].second.first;
				y += vp[j].second.second;
			}ans = max(ans, x * x + y * y);
		}
	}
    cout.precision(15);
    cout<<fixed<<sqrt(ans)<<endl;
}