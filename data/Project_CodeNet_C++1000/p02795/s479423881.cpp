#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
int main() {

int h,w,n;
 cin>>h>>w>>n;
  int c=0,m=0; 
  if(h>=w){rep(i,w){m+=h;c++;if(m>=n)break;}}
  else{rep(i,h){m+=w;c++;if(m>=n)break;}}
  if(n==0){c=0;}
  cout<<c<<endl;
  
}
