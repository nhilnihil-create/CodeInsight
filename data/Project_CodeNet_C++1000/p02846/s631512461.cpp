#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

const ll X=1000000007;

int main() {
  ll T1,T2,A1,A2,B1,B2,TA,TB,AA,AB,D;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  TA=T1*A1;
  TB=T2*A2;
  AA=T1*B1;
  AB=T2*B2;//高橋青木の前後半で進む距離
  D=TA+TB-AA-AB;
  if(TA+TB==AA+AB){
  cout<<"infinity"<<endl;
  }
  else{
    if(D<0){swap(TA,AA);swap(TB,AB);D=-D;}
    //以降は高橋の方が先に進む場合のみ
    if(TA>AA){cout<<0<<endl;}
    else{
      ll d=AA-TA;
      if(d%D==0){
        cout<<2*(d/D)<<endl;
      }
      else{
        cout<<2*(d/D)+1<<endl;
      }
    }
  }
}

