#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long modpow(long long b, long long i){
  long long s=1;
  while(i){
    if(i%2) s=(s*b)%MOD;
    b=(b*b)%MOD; i/=2;
  }
  return s;
}
int main(){
  clock_t start,end;
  start=clock();

  int x,y; cin >>x >>y;
  int m=2*y-x,n=2*x-y;
  if(m<0||n<0||m%3||n%3){cout <<0; return 0;}
  else{
    long long p=(m+n)/3,q=min(m,n)/3,pp=1,qq=1;
    for(int i=0; i<q; i++){
      pp=(pp*(p-i))%MOD; qq=(qq*(q-i))%MOD;
    }
    cout <<(pp*modpow(qq,MOD-2))%MOD<<endl;
  }

  //end=clock();
  //double time_taken=double(end-start)/double(CLOCKS_PER_SEC); 
  //cout <<"Time taken: "<<fixed<<setprecision(5);
  //cout <<time_taken<<"s/"<<time_taken*1000<<"ms"<<endl;
return 0;}