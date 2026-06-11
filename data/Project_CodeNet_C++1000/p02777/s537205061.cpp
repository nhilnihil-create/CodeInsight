#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string s,t; cin >> s >> t;
  int a,b; cin >> a >> b;

  map<string,int> m;
  m[s] = a;
  m[t] = b;

  string u; cin >> u;
  m[u]--;
  cout << m[s]  << " " <<  m[t] << endl;
}
