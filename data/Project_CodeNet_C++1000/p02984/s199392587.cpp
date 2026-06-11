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
	ll n;
	cin>>n;
	ll a[n],ans[n];
	ans[0]=0;ans[1]=0;
	forn(i,n){
		cin>>a[i];
		(i%2==0)?ans[0]+=a[i]:ans[0]-=a[i];
	}
	forn(i,n){
		(i%2==0 && i>1)?ans[1]-=a[i]:ans[1]+=a[i];
	}
	for(ll i = 2; i<n; i++){
		ans[i] = ans[i-2] + 2*a[i-1] - 2*a[i-2];
	}
	forn(i,n){
		cout<<ans[i];
		(i==n-1)?cout<<"\n":cout<<" ";
	}
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
