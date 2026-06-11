/*                                   *MELLOW THE PANDA*
  `||||||||||||||||||||||!!!||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  `||||||||||||||||||!''      !!||||pp@@@@@@@@@@@@@@@@@@@@@@||||||!'````````||||||||||||||||
   |||||||||||||||!'`         ,g@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@L           `|||||||||||||||
   '||||||||||||'`         ,p@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           `||||||||||||||
   '|||||||||||'         j@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@w          ``||||||||||||
   '||||||||||`        ,g@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,         `||||||||||||
   ||||||||||'       ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@L        `|||||||||||
   '|||||||||       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@p      `'||||||||||
   '|||||||||;,   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,   `<|||||||||||
   '|||||||||||!;p@@@@@@@@M*     **%@&@F***********&@@@@@@N%@@@@@@@@@@@@@@@@w!||||||||||||||
   '||||||||||||j@@@@@@@N  |!"*!,@@@@@[            &@@&@@m        ?@@@@@@@@g||||||||||||||||
   '||||||||||||]@@@@@@@  ||  #r)@@@@@@$,         g@@@@@@@@|"""!|; ]@@@@@@@@@@||||||||||||||
   `||||||||||||]@@@@@@|  ||   g@@@@@@@@@@p    ,@@@@@&@@@@@@|#L !|  %@@@@@@@@@k|||||||||||||
   `||||||||||||]@@@@@@    `||$@@@@N@@@@@@&@$@@$@@@@@@@@@@@@@   ||  ]%@@@@@@@@H|||||||||||||
   `||||||||||||]@@@@@@      ^@@@@@NM@@@@@@@@@ |@@@@@@@@@@@@@@''`    %@@@@@@%%||||||||||||||
    ||||||||||||%@@@@@@      ]B@@@@@@|&@@@@@@@M$@@@@@@@@@/@@@@@      ]@@@@@@@%!!!|||||||||||
    '|||||||||||]@@@@@@o      @@@@@@@@@|N@@@@@ @@@@@@@@@|@@@@@@     ]@@@@@@@%  ```'|||||||||
    '|||||||||||]@@@@@@@      ]@@@@@@@@@@]%@N@ Q@@@@%@[]@@@@@@N    p@@@@@@%M        `|||||||
    `||||||||||||]@@@@@@@;     %N@@@@@@@@@@@@Lj@@gg@@@@@@N@@@N   )@@@@@@@@F          '||||||
    `|||||||||||||]%@@@@@@@r    %@@@@@@@@@@@@@@@@@@@@@@@@@@@K   ]@@@@@@@@h          '`||||||
    `||||||||||||||]@%N%N@@@gm,,  j%@@@@@@@@@@@@@@@@@@@@@%h  ;p@@@@@@@@@F            `||||||
    `|||||||||||||||j%@@@@@@@@@p"..                    ,,;g@@@@@@@@@@*"              `||||||
    `||||||||||||||||||]%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@k@]N"                 '||||||
    `|||||||||||||||'``'"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**'```                        |||||||
    `||||||||||||||'|`     '*@@@@@@@@@@@@@@@@@@@``                                   y||||||
    `'||||||||||||'`            ''"**|||||||||||                                    j|||||||
    ``|||||||||||`                     `'`'|jk*                                   ,j||||||||
    `'|||||||||||                          '`                                   ;p||||||||||
    ``||||||||||'                                                                 `'*j||||||
    ``|||||||||||                                    						              ||
___________________________________________________________________________________________________________________________________________________________*/
#include <bits/stdc++.h> 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define l00p(i, a, b) for (int i=a; i<(b); i++)
#define loop(i, a) for (int i=0; i<(a); i++)
#define rep1(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define imax INT_MAX
#define imin INT_MIN
//#define MOD 998244353
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 
const int MOD = 1000000007;
const char nl = '\n';
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

signed main() {
	 
	//ios_base::sync_with_stdio(0); cin.tie(0); 
	int n;
	cin>>n;
	string s;
	cin>>s;
	int r=count(s.begin(),s.end(),'R');
	int b=count(s.begin(),s.end(),'B');
	int g=count(s.begin(),s.end(),'G');
	ll ans=r*(ll)b*g;
	loop(i,n)
		l00p(j,i+1,n)
		{
			int k=2*j-i;
			if(k>=n)continue;
			
			if(s[i]!=s[k] && s[i]!=s[j] && s[j]!=s[k])
			ans--;
		}
	cout<<ans<<nl;
    
	//return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343