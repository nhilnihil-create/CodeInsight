#define rep(i, m, n) for(int i = m; i < n; i++)
#define repM(i, m, n) for(int i = n-1; i>=m; i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll; using namespace std;
//typedef pair<int,int> pii;
// d = distance(lower_bound(all(x)), upper_bound(all(x)));
int INF = 1e9;
int M = 1e9+7;
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

int main(){
  int N; cin >> N; int K = pow(2,N); int b; multiset<int> p;
  for(int i=0; i<K; i++) {cin >> b; p.insert(b);}
  auto r=p.end(); r--;
  vector<int> v; v.push_back(*r); p.erase(r);
  //int mx = *min_element(p.begin(), p.end());
  //vector<int> v; v.push_back(mx); p.erase(mx);
  
  for(int i=1; i<=N; i++) {
    for(int j=0; j<pow(2,i-1); j++) {
      r = p.lower_bound(v[j]);
      //int r = distance(p.begin(), lower_bound(p.begin(), p.end(), v[j]));
      //cout << *r << " ";
      if (r == p.begin()) {cout << "No" << endl; return 0;}
      else {
        v.push_back(*(--r)); p.erase(r);
      }
    }
  }
  cout << "Yes" << endl;
}