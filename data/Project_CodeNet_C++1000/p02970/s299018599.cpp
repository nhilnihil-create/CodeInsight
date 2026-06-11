#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  int n,d;
  cin>>n>>d;
  d=2*d+1;
  int ans=0;
  while(n>0){
   ans++;
    n-=d;
  }
  cout<<ans<<endl;
}