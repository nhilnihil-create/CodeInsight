#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,m;
  cin >> n >> m;
  d t=0;
  vector<int> a;
  rep(i,n){
    int b;
    scanf("%d",&b);
    a.push_back(b);
    t+=b;
  }
  bool k=0;
  int c=0;
  rep(i,n){
    if(a[i]*4*m>=t)++c;
    if(c==m){
      k=1;
      break;
    }
  }
  if(k) printf("%s\n", "Yes");
  else printf("%s\n", "No");
  return 0;
}
