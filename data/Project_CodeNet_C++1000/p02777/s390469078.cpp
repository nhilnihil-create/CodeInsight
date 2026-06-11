#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define in insert
#define fs first
#define sc second
#define sz size
#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define forni(i, n) for (ll i = 1; i < (ll) (n); ++i)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using ll = long long;
const ll inf = 1e9+7; 
const double PI =  3.141592653589793;

int main(){
	IO;
	map <string, ll> m;
	string s,t;
	cin>>s>>t;
	ll a, b;
	cin>>a>> b;
	m[s]=a; m[t] = b;
	string u;
	cin>>u;
	m[u]--;
	cout<<m[s]<<" "<<m[t]<<"\n";
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
