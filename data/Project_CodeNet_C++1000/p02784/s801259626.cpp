#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  ll h,sum=0,n;
  cin >> h >> n;
  rep(i,n){
    int a; cin >> a;
    sum += a;
  }

  if(sum>=h) puts("Yes");
  else puts("No");
}
