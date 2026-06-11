#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin>>n;
  int n2 = pow(2,n);
  vector<int> s(n2), created;
  REP(i,n2){
	cin>>s[i];
  }
  sort(ALL(s));
  created.push_back(s.back());
  s.pop_back();
  REP(i,n){
    REP(j,pow(2,i)){
//      int a = s.back();
//      s.pop_back();
      auto itr = lower_bound(ALL(s),created[j]);
//      cout << created[j] << " " << a << endl;
      if(itr==s.begin()){
        cout << "No" << endl;
        return 0;
      }else{
        itr--;
        created.push_back(*itr);
        s.erase(itr);
      }
    }
//    cout << endl;
  }
  if(created.size()==n2&&s.size()==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}