#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

template<typename T>
vector<T> factor(T n) {
    vector<T> factorization;
    while (n%2==0) {
        factorization.push_back(2);
        n/= 2;
    }
    for (T d=3; d*d<=n; d+= 2) {
        while (n%d==0) {
            factorization.push_back(d);
            n/= d;
        }
    }
    if (n>1)
        factorization.push_back(n);
    factorization.pb(1);
    return factorization;
}

int main(){
    
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<n;++i){
		ans+=(n-1)/i;
	}
	
	printf("%lld\n",ans);

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}
