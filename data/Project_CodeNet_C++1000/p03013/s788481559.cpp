#include <bits/stdc++.h>
using namespace std;

#define BROKE 1

int main() {

  int64_t n,m;
  cin>>n>>m;
  
  
  //n段目に来るルートは１段前から来るか、2段前から来るか
  //ただし、1段目か2段目が壊れていたら来れない
  //格段のルート数の足し算が移動方法になる

  //壊れた床の場所を格納
  vector<int64_t> broken(n+1);
  for(int i=0;i<m;i++){
    int wk=0;
    cin>>wk;
    broken.at(wk)=BROKE;
  }

  //移動方法を調べる
  vector<int64_t> route(n+1);
  route.at(0)=1;
  for(int i=1;i<=n;i++){
    int route1,route2;
    if(broken.at(i-1)==BROKE)
      route1 = 0;
    else
      route1 = route.at(i-1);
    
    if(i<2 || broken.at(i-2)==BROKE)
      route2 = 0;
    else
      route2 = route.at(i-2);
    
    if(broken.at(i)==BROKE)
      route.at(i)=0;
    else
      route.at(i) += (route1+route2)%1000000007;
  }

  cout<<route.at(n)<<endl;

  return 0;
}
