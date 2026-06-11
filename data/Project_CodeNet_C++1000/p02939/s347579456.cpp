#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstring>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;


int main() {
  string s;
  cin >> s;

  vector<string> res;

  string last = s.substr(0, 1);
  res.pb(last);
  s = s.substr(1);

  while (s.size() > 0) {
    string now = s.substr(0, 1);

    if (now == last) {
      if(s.size() == 1) {
	break;
      } else {
        last = s.substr(0, 2);
	s = s.substr(2);
	res.pb(last);
      }
    } else {
      last = now;
      s = s.substr(1);
      res.pb(last);
    }
  }

  cout << res.size() << endl;
  return 0;
}
