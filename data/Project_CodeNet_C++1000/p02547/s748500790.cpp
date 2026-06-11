#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  ll n,m,x,y,cnt=0;
  cin >> n;

  for(int i=0; i < n; i++){
    cin >> x >>y;
    if(x==y)cnt++;
    else cnt=0;
    if(cnt==3){
      cout<<"Yes"<<endl;
      return;
    }
  }
  cout<<"No"<<endl;

}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}