#include <functional>  
#include <iostream>    
#include <map>       
#include <set>        
#include <string>     
#include <utility>     
#include <vector>      

using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
#define pi acos(-1.0)
#define MAX 10000001
//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
  map<string, int> mm;
  int cases;
  cin >> cases;
  while (cases--) {

    string s;
    cin >> s;

    if (mm.find(s) == mm.end()) {
      mm[s] = 1;
    } else {
      mm[s]++;
    }
  }

  set<int, greater<int>> sss;
  for (auto itr : mm) {
    sss.insert(itr.second);
  }
  auto store = *sss.begin();
//   cout << store << endl;
  

for(auto itr : mm){
    // cout << itr.first << " ----" << itr.second << endl;
    if(itr.second == store){
        cout << itr.first << endl;
    }
}

  /* MAIN Code ENDS here: */
  
}