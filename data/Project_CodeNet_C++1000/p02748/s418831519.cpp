#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,M,aa = 1000000,bb = 1000000;
  cin >> A >> B >> M;
  vector<int>a(A);
  vector<int>b(B);
  for(int i=0; i<A; i++){
    cin >> a[i];
    aa = min(aa,a[i]);
  }
  for(int i=0; i<B;i++){
    cin >> b[i];
    bb = min(bb,b[i]);
  }
  int abab = aa+bb,qupon = 1000000;
  for(int i=0; i<M; i++){
    int x,y,z;
    cin >> x >> y >> z;
    qupon = min(a[x-1] + b[y-1] - z,qupon);
  }
  cout << min(abab,qupon) << endl;            
}