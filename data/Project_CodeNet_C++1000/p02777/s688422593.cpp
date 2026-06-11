#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if(s==u) a--;
  else b--;
  cout << a << " "<< b;
  return 0;
}
