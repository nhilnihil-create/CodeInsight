#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=998244353;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
//18:08~
int main(void){
	cout<<fixed<<setprecision(20);
	cin.tie(0);ios::sync_with_stdio(false);
	int i,n;cin>>n;
	vector<tuple<double,double,double>>eng(n+n+1);
	llint nx=0,ny=0,ans=0;
	for(i=0;i<n;i++){
		double x,y,arg;
		cin>>x>>y;
		arg=atan2(x,y);
		eng[i]=mt(arg,x,y);
		eng[i+n]=mt(arg+pai+pai,x,y);
	}
	eng[n+n]=mt(9999.0,0.0,0.0);
	SO(eng);
	int hi=0,mg=0;
	while(hi<n+n){
		if(get<0>(eng[hi])+pai<get<0>(eng[mg])){nx-=get<1>(eng[hi]);ny-=get<2>(eng[hi]);hi++;}
		else{nx+=get<1>(eng[mg]);ny+=get<2>(eng[mg]);mg++;}
		maxeq(ans,nx*nx+ny*ny);
	}
	cout<<sqrt(ans)<<endl;
	return 0;
}