#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;
  

int main() {
  int a[4],b[4];
  
  while(cin>>a[0]){
    rep(i,3) cin>>a[i+1];
    rep(i,4) cin>>b[i];
    int h=0,v=0;
    
    rep(i,4){
      if(a[i]==b[i]) h++;
    }
    rep(i,4){
      rep(j,4){
        if(a[i]==b[j]) v++;
      }
    }
    
    cout<<h<<" "<<v-h<<endl;

  }
  
  return 0;
}
