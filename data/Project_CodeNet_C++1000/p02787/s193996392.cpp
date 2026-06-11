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

int main(){
	IO;
	ll h,n,a,b;
	cin>>h>>n;
	ll dp[h+1];
	forn(i,h+1) dp[i]=inf;
	dp[0]=0;
	forn(i,n){
		cin>>a>>b;
		forn(j,h){
			dp[min(j+a,h)]=min(dp[min(j+a,h)],dp[j]+b);
		}
	}
	cout<<dp[h]<<'\n';
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
 
