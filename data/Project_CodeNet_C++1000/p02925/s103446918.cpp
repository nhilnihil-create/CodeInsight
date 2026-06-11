#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x,  k;
string s, t;

// <------------- Implement Functions Here ----------> //

queue<ll> q[2000];
ll m[2000][2000] = {};
queue<ll> q1,q2;

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n ;
	ll cnt = 0,day = 0;

	for(ll i=1;i<=n;i++) {
		for(ll j=1;j<n;j++) {
			cin>>x;
			q[i].push(x);
		}
	}

	for(ll i=1;i<=n;i++) q1.push(i);

	while(!q1.empty()) {
		++ day;
		
		while(!q1.empty()) {
			ll x = q1.front();q1.pop();
			ll y = q[x].front();

			m[x][y] = 1;

		
			if(m[x][y] == m[y][x]) {
				q[x].pop();
				q[y].pop();
				
				cnt+=2;

				if(!q[x].empty()) q2.push(x);
				if(!q[y].empty()) q2.push(y);
			}
		}

		while(!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}
	}

	if(cnt == n*(n-1))  cout<<day;
	else 				cout<<-1;
	newl;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}