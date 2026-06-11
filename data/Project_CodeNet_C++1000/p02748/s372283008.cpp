#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int a,b,m,mi;
  cin >> a >> b >> m;
  vector<int>A(a);
  vector<int>B(b);
  vector<int>AA;
  vector<int>BB;
  rep(i,a) cin >> A[i];
  rep(i,b) cin >> B[i];
  AA = A;
  BB = B;
  sort(AA.begin(),AA.end());
  sort(BB.begin(),BB.end());
  mi = AA[0]+BB[0];
  rep(i,m){
    int x,y,c;
    cin >> x >> y >> c;
    x--;y--;
    mi = min(mi,A[x]+B[y]-c);
  }
  cout << mi << endl;
}