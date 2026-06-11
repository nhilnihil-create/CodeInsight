#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(int i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll INF = 1000000000000000;
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

signed main(){
	IO_STREAM;
	int N;
	cin>>N;
	vi A(N);
	int x[N][N]={0},y[N][N]={0};
	rep(i,0,N){
		cin>>A[i];
		rep(j,0,A[i]){
			cin>>x[i][j];	cin>>y[i][j];
		}
	}
	int ans=0;
	rep(bit,0,(1<<N)){
		int ng=0;
		int cnt=0;
		DBG("bit=",bit,"","");
		rep(i,0,N){
			if (bit & (1<<i)){
				rep(m,0,A[i]){
					DBG("i=",i,"m=",m);
					DBG("y[i][m]=",y[i][m],"x[i][m]=",x[i][m]);
					DBG("bit=",bit,"1<<x=",(1<<(x[i][m]-1)));
					int calc=bit&(1<<(x[i][m]-1));
					DBG("calc=",calc,"","");
					if(y[i][m]==1&& calc==0  ){
//					if(y[i][m]==1&& (bit&(1<<(x[i][m]-1))==0)  ){
						ng=1;break;
					}
					if(y[i][m]==0&&calc){
//					if(y[i][m]==0&&(bit&(1<<(x[i][m]-1)))){
						ng=1;break;
					}
				}
				if(ng) break;
				cnt++;
			}
		}
		DBG("cnt=",cnt,"ng=",ng);
		if(ng==0){
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}
