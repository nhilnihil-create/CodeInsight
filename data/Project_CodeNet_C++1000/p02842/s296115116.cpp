#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main() {
  int n; cin>>n;
  REP(i,55000){
    if((int)(i*1.08)==n){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<":("<<endl;
}