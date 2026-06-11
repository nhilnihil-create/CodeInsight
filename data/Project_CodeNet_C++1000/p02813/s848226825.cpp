#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int n;
  cin >> n;
  vector<int> p(n), q(n), r(n);;
  rep(i,n) cin >> p[i];
  rep(i,n) {
    cin >> q[i];
    r[i] = q[i];
  }
  sort(r.begin(),r.end());

  int a,b;
  int i = 0;
  do{
    i++;
    if(r == p) a = i;
    if(r == q) b = i;
  }while(next_permutation(r.begin(),r.begin()+n));

  cout << abs(a-b) << endl;
  
}
