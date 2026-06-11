#include <bits/stdc++.h>

#define cn count
#define pb push_back
#define in insert
#define fs first
#define sc second
#define sz size
#define len length
#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define forni(i, n) for (ll i = 1; i < (ll) (n); ++i)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using ll = long long;
const ll inf = 1e9+7; 
const double PI =  3.141592653589793;

bool isSquare(ll x){
	long double sq = sqrt(x*1.0);
	return (sq - floor(sq))==0;
}

int main(){
	IO;
	ll n,d,ans=0,cnt;
	cin>>n>>d;
	ll x [n][d];
	forn(i,n){
		forn(j,d){
			cin>>x[i][j];
		}
		forn(j,i){
			cnt = 0;
			forn(k,d){
				cnt+= pow(abs(x[i][k] - x[j][k]),2);
			}
			if(isSquare(cnt))ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

// _   .-')                .-. .-')                 .-')                                               
//( '.( OO )_              \  ( OO )               ( OO ).                                             
// ,--.   ,--.).-'),-----. ,--. ,--.  .-'),-----. (_)---\_) ,--. ,--.     .-----.  ,-.-')  .-'),-----. 
// |   `.'   |( OO'  .-.  '|  .'   / ( OO'  .-.  '/    _ |  |  | |  |    '  .--./  |  |OO)( OO'  .-.  '
// |         |/   |  | |  ||      /, /   |  | |  |\  :` `.  |  | | .-')  |  |('-.  |  |  \/   |  | |  |
// |  |'.'|  |\_) |  |\|  ||     ' _)\_) |  |\|  | '..`''.) |  |_|( OO )/_) |OO  ) |  |(_/\_) |  |\|  |
// |  |   |  |  \ |  | |  ||  .   \    \ |  | |  |.-._)   \ |  | | `-' /||  |`-'| ,|  |_.'  \ |  | |  |
// |  |   |  |   `'  '-'  '|  |\   \    `'  '-'  '\       /('  '-'(_.-'(_'  '--'\(_|  |      `'  '-'  '
// """    """     """""""" """  """"      """""""  """""""  """"""""      """"""   """         """""""
