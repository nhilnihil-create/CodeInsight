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
//16:35~
int main(void){
	cout<<fixed<<setprecision(20);
	cin.tie(0);ios::sync_with_stdio(false);
	//saで殴った方が早い
	int n,i;cin>>n;
	llint sai=0;
	vector<llint>a(n);
	for(i=0;i<n;i++){cin>>a[i];sai^=a[i];}
	for(i=0;i<n;i++){a[i]-=(a[i]&sai);}
	//最大化 吐き出し法
	int bas=0;
	while(-1){
		for(i=bas+1;i<n;i++){if(a[bas]<a[i]){swap(a[bas],a[i]);}}
		if(a[bas]==0){break;}
		for(i=bas+1;i<n;i++){mineq(a[i],a[i]^a[bas]);}
		bas++;
		if(bas>=n){break;}
	}
	llint ans=0;
	for(i=0;i<n;i++){maxeq(ans,ans^a[i]);}
	cout<<sai+ans*2<<endl;
	return 0;
}