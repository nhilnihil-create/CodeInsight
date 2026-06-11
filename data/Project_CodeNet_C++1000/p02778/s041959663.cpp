#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<iomanip>
#include<sstream>

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cout << '\n';}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << '[' << *it << " = " << a << "]  ";
    err(++it, args...);
}

#define fcout cout<<fixed<<setprecision(15)
#define repp(i,j,k) for(int i=j; i<k; ++i)
#define rep(i,j) repp(i,0,j)
#define rrep(i,j,k) for(int i=j; i>=k; --i)
#define all(x) (x).begin(), (x).end()
#define sort(x) sort(x.begin(), x.end())
#define lb(x,val) lower_bound(x.begin(), x.end(), val)
#define ub(x,val) upper_bound(x.begin(), x.end(), val)
#define pb(x) emplace_back(x);

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef tuple<lli, lli> tii;
typedef tuple<lli, lli, lli> tiii;

//const lli M=998244353ll;
const lli M=1000000007ll;
const double D=1.0;


void solve(){
	string s; cin>>s;
	rep(i,s.size()) cout<<"x";

}

int main(){
	fast_io
	int tc=1;
	//cin>>tc;
	while(tc--){solve();}
	return 0;
}