#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  ll T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  if(T1*A1+T2*A2==T1*B1+T2*B2){
    cout<<"infinity"<<endl;
  }else{
    ll dx1=T1*B1-T1*A1;
    ll dx2=T1*B1+T2*B2-T1*A1-T2*A2;
    if((dx1>0&&dx2>0)||(dx1<0&&dx2<0)){
      cout<<0<<endl;
    }else{
      if(dx1<0){
        dx1=-dx1;
      }else{
        dx2=-dx2;
      }
      if(dx1%dx2==0){
        cout<<dx1/dx2*2<<endl;
      }else{
        cout<<dx1/dx2*2+1<<endl;
      }
    }
  }
}
