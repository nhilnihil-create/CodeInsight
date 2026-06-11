#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  ll h;
  cin >> h;
  ll m = h;
  //cout << h << endl;
  ll counts =0;
  if(h == 1) cout << 1 << endl;
  else{
   while(h!=1){
          h = h/2;
     counts++;

   }
  ll sum =0;
  rep(i,counts+1){
    sum += pow(2,i);
  }
  cout << sum << endl;
  }
}
