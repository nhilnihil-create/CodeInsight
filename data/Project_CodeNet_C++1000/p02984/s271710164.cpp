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
int main(){
	int n;
	//int ans=0;
	cin >>n;
	vector<ll>a(n);
	V ans(n,0LL);
	ll sum=0LL;
	rep(i,n){
		cin>>a[i];
		a[i]*=2LL;
		if(i%2){
			sum-=a[i];
		}else{
			sum+=a[i];
		}
	}
	ans[0]=sum/2;
	//clog<<ans[0]<<endl;
	ans[1]=(a[0]/2 -ans[0]/2)*2;
	//clog<<ans[1]<<endl;
	for(int i=2;i<n;i++){
		ans[i]=(a[i-1]/2 - ans[i-1]/2)*2;
		//ans[1]=(a[0]/2 -ans[0]/2)*2;
	}
	rep(i,n){
		cout<<ans[i];
		if(i!=n-1){
			cout<<" ";
		}
	}
	cout<<endl;
}
/*
a_1 = f_(n-1) + f_0
a_2 = f_(0) + f(1)
.
.
.
a_n = f_(n-2)+ f(n-1)

*/

/*
2*2 = f_2 + f_0  +
2*2 = f_0 + f_1  -
4*2 = f_1 + f_2  +

4*2 = 8= 2 *f_2 =.> f_2 = 4 



*/