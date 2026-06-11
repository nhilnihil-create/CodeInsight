#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int c,d;
  c = stoi(a);
  d = stoi(b);
  string e,f;
  rep(i,d) e += a;
  rep(i,c) f += b;
  if(a < b) cout << e << endl;
  else cout << f << endl;
}