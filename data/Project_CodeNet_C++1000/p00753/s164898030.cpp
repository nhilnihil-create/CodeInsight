#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a,c) memset(a,c,sizeof(a))

#define DEBUG(x) cout<<"#x"<<": "<<x<<endl

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = INT_MAX/3;
const ll MOD = 1000000007;
const double EPS = 1e-14;
const int dx[] = {1,0,-1,0} , dy[] = {0,1,0,-1};

int main(){
    vector<int> primes;
    primes.PB(2);
    FOR(i,3,300000){
	bool flg = true;
	for(int j=0;j<primes.size()&&primes[j]*primes[j]<=i;j++){
	    if(i % primes[j] == 0){
		flg = false;
		break;
	    }
	}
	if(flg){
	    primes.PB(i);
	}
    }

    while(true){
	int n;
	cin >> n;
	if(n==0) break;
	int s = upper_bound(ALL(primes),n) - primes.begin();
	int t = upper_bound(ALL(primes),2*n) - primes.begin();
	cout << t-s << endl;
    }

    return 0;
}