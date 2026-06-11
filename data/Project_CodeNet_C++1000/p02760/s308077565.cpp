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
#define int long  long
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
    // freopen("a.in", "r", stdin);
//    freopen("logs.out", "w", stdout);
}

void solve(){
    vvi kek(3, vi(3));
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> kek[i][j];
    map<int, bool> used;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int beta;
        cin >> beta;
        used[beta] = true;
    }
    bool ans = false;
    ans |= used[kek[0][0]]&&used[kek[0][1]]&&used[kek[0][2]];
    ans |= used[kek[1][0]]&&used[kek[1][1]]&&used[kek[1][2]];
    ans |= used[kek[2][0]]&&used[kek[2][1]]&&used[kek[2][2]];
    ans |= used[kek[0][0]]&&used[kek[1][1]]&&used[kek[2][2]];
    ans |= used[kek[2][0]]&&used[kek[1][1]]&&used[kek[0][2]];
    ans |= used[kek[0][0]]&&used[kek[1][0]]&&used[kek[2][0]];
    ans |= used[kek[0][1]]&&used[kek[1][1]]&&used[kek[2][1]];
    ans |= used[kek[0][2]]&&used[kek[1][2]]&&used[kek[2][2]];
    if(ans){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}
 
signed main(){
    fast_io();
    srand(time(NULL));
    cout << fixed << setprecision(12);
    int q = 1;
    // cin >> q;
    while(q--)
        solve();
     
}
