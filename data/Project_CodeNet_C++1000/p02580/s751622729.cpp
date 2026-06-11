#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#define MOD 1000000007LL

int h,w;
int m;
set<pair<int, int>> t;
set<int> vt;
set<int> hr;
map<int, int> vn;
map<int, int> hn;
multimap<int, int> rvn;
multimap<int, int> rhn;

int main()
{
  ll ans=0;

  cin >> h >> w >> m;
  for (int i=0; i<m; i++) {
    int hi, wi;
    cin >> hi >> wi;
    t.insert(make_pair(hi, wi));
    vt.insert(hi);
    hr.insert(wi);
    if (vn.count(hi) > 0) {
      vn[hi]++;
    } else {
      vn[hi]=1;
    }
    if (hn.count(wi) > 0) {
      hn[wi]++;
    } else {
      hn[wi]=1;
    }
  }
  /*
  for (auto hit=hr.begin(); hit!=hr.end(); hit++) {
    for (auto vit=vt.begin(); vit!=vt.end(); vit++) {
      auto fit=t.find(make_pair(*vit, *hit));
      if (fit != t.end()) {
        if (vn.count(*vit) > 0) {
          vn[*vit]++;
        } else {
          vn[*vit]=1;
        }
        if (hn.count(*hit) > 0) {
          hn[*hit]++;
        } else {
          hn[*hit]=1;
        }
//printf("(%d %d)\n", *vit, *hit);
      }
    }
  }
    */

  for (auto vit=vn.begin(); vit!=vn.end(); vit++) {
//    printf("vn[%d] = %d\n", vit->first, vit->second);
    rvn.emplace(vit->second, vit->first);
  }
  for (auto hit=hn.begin(); hit!=hn.end(); hit++) {
//    printf("hn[%d] = %d\n", hit->first, hit->second);
    rhn.emplace(hit->second, hit->first);
  }
  /*
  for (auto vit=rvn.rbegin(); vit!=rvn.rend(); vit++) {
    printf("rvn[%d] = %d\n", vit->first, vit->second);
  }
  for (auto hit=rhn.rbegin(); hit!=rhn.rend(); hit++) {
    printf("rhn[%d] = %d\n", hit->first, hit->second);
  }
*/

  ans = rvn.rbegin()->first + rhn.rbegin()->first - 1;
  for (auto vit=rvn.rbegin(); vit != rvn.rend() && vit->first == rvn.rbegin()->first; vit++) {
    for (auto hit=rhn.rbegin(); hit != rhn.rend() && hit->first == rhn.rbegin()->first; hit++) {
      auto fit=t.find(make_pair(vit->second, hit->second));
      if (fit == t.end()) {
        ans++;
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
