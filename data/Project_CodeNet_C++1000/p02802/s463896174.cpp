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
	ll n,m,p,pen = 0;
	string s;
	cin>>n>>m;
	map<ll,ll>score;
	set<ll>st;
	forn(i,m){
		cin>>p>>s;
		if(st.cn(p)==0){
			if(s=="WA"){
				score[p]++;
			}else {st.in(p); pen+=score[p];}
		}
	}
	cout<<st.sz()<<" "<<pen<<"\n";
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

