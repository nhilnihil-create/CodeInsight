#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n;
  cin >> n;
  ll V =0, E=0;
  for(int i=1;i<=n;++i) V+= ll(i)*(n-i+1);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    if(a>b) swap(a,b);
    E+= ll(a)*(n-b+1);
  }
  ll ans=V-E;
  cout << ans << "\n";
  return 0;
}