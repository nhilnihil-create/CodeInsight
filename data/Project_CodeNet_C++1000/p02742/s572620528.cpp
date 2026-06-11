#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
typedef long long ll;

int main() {
  ll h,w; cin>>h>>w;
  if(h==1||w==1) cout<<"1"<<endl;
  else cout<<(ll)((h+1)/2)*(ll)((w+1)/2)+(ll)(h/2)*(ll)(w/2)<<endl;
}