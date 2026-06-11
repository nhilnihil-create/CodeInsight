#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n,m;
  string s;
  cin >>s;
  auto a=s.end()-1;
  if(*a=='s')s+="es";

  else s+="s";
  cout << s<<endl;

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