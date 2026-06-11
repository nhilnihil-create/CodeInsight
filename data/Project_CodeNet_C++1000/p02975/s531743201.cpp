#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/
signed main() {
  int n;
  cin >> n;
  map<int, int> mp;
  bool all_zero = true;
  REP(i,n) {
    int tmp;
    cin >> tmp;
    if(tmp) all_zero = false;
    ++mp[tmp];
  }
  if(all_zero) {
    cout << "Yes" << endl;
    return 0;
  }
  int input_count = mp.size();
  if(input_count > 3 || input_count < 2) {
    cout << "No" << endl;
    return 0;
  }
  if(n%3) {
    cout << "No" << endl;
    return 0;
  }
  int third_n = n / 3;
  if(input_count==2) {
    REPOBJ(itr, mp) {
      if(itr->first == 0) {
        if(itr->second != third_n)  {
          cout << "No" << endl;
          return 0;
        }
      } else {
        if(itr->second != third_n*2) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  } else {
    int should_be_zero = 0;
    REPOBJ(itr, mp) {
      should_be_zero ^= itr->first;
      if(itr->second != third_n) {
        cout << "No" << endl;
        return 0;
      }
    }
    if(should_be_zero) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes";
  cout << "\n";
  return 0;
}
/***** MAIN *****/
