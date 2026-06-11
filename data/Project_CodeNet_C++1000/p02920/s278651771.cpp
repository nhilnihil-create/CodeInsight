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
	int h,i,n,m;cin>>n;
	m=(1<<n);
	multiset<int>a;
	for(i=0;i<m;i++){int x;cin>>x;a.ins(x);}
	vector<int>b;
	b.pub(*prev(a.end()));
	a.erase(*prev(a.end()));
	for(h=0;h<n;h++){
		vector<int>c;c.reserve(1<<h);
		for(auto it:b){
			auto sor=a.lower_bound(it);
			cerr<<it<<endl;
			if(sor==a.begin()){cout<<"No"<<endl;return 0;}
			sor--;
			cerr<<(*sor)<<endl;
			c.pub(*sor);
			a.era(sor);
			
		}
		for(auto it:c){b.pub(it);}
	}
	cout<<"Yes"<<endl;
	return 0;
}