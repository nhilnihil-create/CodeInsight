/*
                                                                                                     
                                             `-:://:::-                                             
                                           `//:-------:/:`                                          
                                          .+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .o:--...```..---+/`                                        
                                       `/y+o/---....---:+o.                                         
                                   `...````-os+/:---:/+o/--.`                                       
              `-/+++++/:.      `...`       :h+d+oooo+/+-`   ...                                     
            `/++//:::://++-`....`         -.`//````````:`     `..`                                  
           `o+/::------://o/`           `-` -.          -`       `..`                               
 `---.-o/:./o/::-..``..-ЗАПУСКАЕМ      ..  ..            -`        `...       ``..``                
  `....o+:-++/:--.```..-://s.        `-`  .-              -`          `-o: .-//::::/:-`             
          `:s+/:--....-::/+s-`      .-   `-                -`           -///:--------:/:`           
           ./s+//:::::://oo-``..НЕЙРОННУЮ: СЕТЬ:::::::-`РАБОТЯГИ        `+:--........--:/`          
            .:ooo+++++osso-`    `.:-...`/` ./::-------:/:`   -`         :+--..``````.--:+:...-+:-`  
             `.-/+++++/+-.-`    -.   ``:so:/:--.......--:+`  `-```````o+/+--..`````..--:o/-..:s+:.  
                 ```````:``.. `-`     -` `+:--..`````..--/+-.../.`````..-o:--.......---/o.    `     
                        `:  `:-      -.  .o:--..`` ``..--:o`   `-`      `:o+:--------:+o-`          
                         `-`-...    ..   .o/--...```..--:+/`    `-`     `oy/so/////++o/.`           
                          -/`  `-` `- ``+s/o/:---...---:++.      `-`   .-../d://///:-.`             
                `.---..``-..-    .-/..`````-oo+/:::::/+o+-        `-``-`  `-.  ````                 
             `:++++/+++++-  ..``.-/:`      /y-:/++o++/:.`..`       ./.   `-                         
            -++/::::::://+/..:-``:` ..   `-.`  ```.```    `..`   `..`-` `-                          
       ``  -o//:--....-::/++` -.-`   `-`.-`                 `..`..`  `-.-                           
  -----ss+:++/:--.```..-://s.  /.     `::                    `-:.     ./`                           
  `````/:..+o/::-..``.--:/+s. ..-`   `-``-`                 ..` `-`  `-`-`                          
          `-s+/::-----::/+oo---``-` ..    .:-    ```      .-`     .-.-  `-`                         
           `:oo+//::://+os/..:`..-/:`      :y.-:::::::.`.-`        ./-`  `-`                        
            `./+oooooooo+/.`-    .-:...`.. .//:-------://`        `- `..` `:.                       
              ``.-::::-.``-/`  `-` `-  `oo:+:--.......--:/`      `-    `.:--h.``..```               
                          -.-`.-    .-   `+:--..`````..--//`    `-       /s-//::::::::.             
                         -` `/-      ..  .o:--..`` ``..--:o.```.-        `//:--------://`           
                        -` .-`.-`     -.`-o/--...```..--:+/.``-:....``:-.+:--....`...--:+`          
                       ..`-.   `-.   ``:os:o/:---...---:++.  `-     ``///+:-..``````.--:+-````-.`   
              `.:///////.-`      .:-..` -``-+o+/:::::/+o/.  `-         `:+:-..`````..--:o/:--/ys+-  
            `-++///////+o/. ``....`-.    :` `.:++++++/:.`  .-           -o/---......---/o.   `.`    
           `++//:-----::/+o:..`     .-`   :    ```````    .-           `+so+:--------:++-`          
  `````:-``:o/::-..`..--:/+o`         -.  `-             .-          `../../+o+////+o+:.`           
  -----syo/o+/:--.```..-://s.          .-` `-           .-        `...     ``-:////:-``             
       .` `/s//:--....-::/+s.            -. `-`        .-       `..`                                
           .+o+/:::--:://+s/-..`          .::+y  ```  .-     `..`                                   
            ./oo++////+oso-`   `....       :y-+:::::::/`   ...                                      
             `.:+oooooo/-`         `....-. .//:-------:/:-.`                                        
                ``...``                 /+:+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .+/--...```..--:+/`                                        
                                         `-o/:---...---:++.                                         
                                          `-+o+/:---:/+o/.                                          
                                            `.:+oooo+/-.`                                           
                                               ``````                                               
*/
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define DEBUG
#define fi first
#define se second
#define pqueue priority_queue
#define pb(x) push_back(x)
//#define endl '\n'
#define all(x) x.begin(), x.end()
#define int long long
#define mk(a, b) make_pair(a, b)
     
using namespace std;
      
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ull> vull;
typedef vector<ll> vll;
// typedef tuple<ll, ll, ll> tiii;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector< vector<ll> > vvll;
typedef vector<char> vc;
      
const ll INF = 1e9 + 228;
const ll INFLL = 1e18;
const ll MOD = 1e9 + 7;
//static const int maxn = 1e6 + 228;
const ld eps = 1e-6;
const ld eps2 = 1e-9;
const ll MOD2 = 998244353;
const ll dosz = 5e5;
const ll SZ = (1<<18);
const ld PI = atan2l(0, -1);
     
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("cowjog.in", "r", stdin);
//    freopen("cowjog.out", "w", stdout);
}

int n;
const int maxn = 1e5+228;
vi g[maxn];
map<int, map<int, int> > kek;

void dfs(int v, int p=-1, int p_color = 0){
	set<int> lol;
	for(int i=1; i<=g[v].size(); i++){
		lol.insert(i);
	}
	lol.erase(p_color);
	for(int i:g[v]){
		if(i==p)
			continue;
		kek[i][v] = *lol.begin();
		kek[v][i] = *lol.begin();
		dfs(i, v, *lol.begin());
		lol.erase(lol.begin());
	}
}

void solve(){
	cin >> n;
	vpii edges(n-1);
	int ans = 0;
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		edges[i] = make_pair(a, b);
		ans = max(ans, (int)max(g[a].size(), g[b].size()));
	}
	dfs(0);
	cout << ans << endl;
	for(int i=0; i<n-1; i++){
		cout << kek[edges[i].first][edges[i].second] << endl;
	}
}

signed main(){
        fast_io();
	srand(time(NULL));
	cout << fixed << setprecision(12);
	int q = 1;
//	cin >> q;
	while(q--)
		solve();
     
}





