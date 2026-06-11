#include<iostream>
#include<set>
using namespace std;

int main() {
  int X,N,i,p;
  set<int> P;
  cin>>X>>N;
  for (i=0;i<N;i++) {
    cin>>p;
    P.insert(p);
  }
  int ans = X;
  if (P.count(X)) {
    for (i=1;i<=100;i++) {
      if (!P.count(X-i)) {
        ans = X-i;
        break;
      }
      if (!P.count(X+i)) {
        ans = X+i;
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
