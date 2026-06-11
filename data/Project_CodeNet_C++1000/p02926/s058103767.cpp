#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N;
struct S{
	double x,y,hen;
	bool operator<(S a){return hen<a.hen;}
};
S s[105];
signed main(){
	cin>>N;
	rep(i,N){
		cin>>s[i].x>>s[i].y;
		s[i].hen=atan2(s[i].y,s[i].x);
	}
	sort(s,s+N);
	double ans=0;
	rep(i,N){
		double nowx=0,nowy=0;
		for(int j=i;j<i+N;j++){
			nowx+=s[j%N].x;nowy+=s[j%N].y;
			chmax(ans,sqrt(nowx*nowx+nowy*nowy));
		}
	}
	printf("%.12lf\n",ans);
}
