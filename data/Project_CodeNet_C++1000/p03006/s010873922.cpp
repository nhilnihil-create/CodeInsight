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

struct ball
{
	ll x, y;
};

int main(){
	startTime=clock();
	int n;
	cin >> n;
	ball b[n];
	FOR(i,n){
		cin >>b[i].x >> b[i].y;

	}
	map<pair<ll,ll>,int> m;
	int maxi=0;
	pair<ll,ll> p;
	FOR(i,n){
		for(int j=0;j < n;j++){
			if(j!=i){
				m[MP(b[i].x-b[j].x,b[i].y-b[j].y)]++;
				if(m[MP(b[i].x-b[j].x,b[i].y-b[j].y)] > maxi) {
					p=MP(b[i].x-b[j].x,b[i].y-b[j].y);
					maxi=m[MP(b[i].x-b[j].x,b[i].y-b[j].y)];
				}
			}
		}
	}
		
	cout << n-maxi;	

	return 0;
}