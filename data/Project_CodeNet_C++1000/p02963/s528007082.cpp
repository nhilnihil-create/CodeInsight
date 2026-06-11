#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}
ll mod=1e18;
int main(){
	startTime=clock();
	ll s;
	cin >> s;
	ll x1,y1,x2,y2,x3,y3;
	x1=0ll;
	y1=0ll;
	x2=1e9;
	y2=1;
	x3=(mod-s)%1000000000;
	y3=(s+x3)/1000000000;
	cout << x1 << " " << y1 <<" "
	<< x2 << "  " << y2 <<	" "
	<< x3 << " " << y3;
		

	return 0;
}


// x2y3-x3y2
// cy3-x3