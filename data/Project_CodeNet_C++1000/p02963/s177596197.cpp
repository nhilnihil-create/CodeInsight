#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  ll S;
  cin>>S;
  ll X1,Y1,X2,Y2;
  X2=(int)sqrt((double)S);
  Y1=X2;
  if(S==X2*Y1){
    X1=0;
    Y2=0;
  }else{
    Y1++;
    ll x=X2*Y1-S;
    if(x<0){
      X2++;
      x=X2*Y1-S;
    }
    X1=1;
    Y2=x;
  }
  cout<<0<<" "<<0<<" "<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<endl;
}
