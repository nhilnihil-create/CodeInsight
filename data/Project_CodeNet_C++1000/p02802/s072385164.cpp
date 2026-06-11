#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool> AC(n,0);
  vector<int> WA(n,0);

  rep(i,m) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if(AC[p] == 1) continue;
    if(s=="AC") AC[p] = 1;
    if(s=="WA") WA[p] += 1;
  }
  
  int total_AC=0, total_WA=0;
  rep(i,n){
    total_AC += AC[i];
    if(AC[i]) total_WA += WA[i];
  }
  cout << total_AC << " " << total_WA << endl;
  
  
}
