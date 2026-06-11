#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int n,k;
  int r,s,p;
  string t;
  cin >> n >> k;
  cin >> r >> s >> p;
  cin >> t;

  vector<char> c(n);
  for(int i=0;i<n;i++){
    if(t[i] == 'r') c[i] = 'p';
    else if(t[i] == 's') c[i] = 'r';
    else if(t[i] == 'p') c[i] = 's';
    if(i >= k){
      if(c[i] == c[i-k]){
        c[i] = 'n';
      }
    }
  }

  ll ans = 0;
  for(int i=0;i<n;i++){
    if(c[i] == 'r') ans += r;
    else if(c[i] == 's') ans += s;
    else if(c[i] == 'p') ans += p;
  }

  cout << ans << endl;

}