#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long modpow(long long b, long long i){
  long long s=1;
  while(i){
    if(i%2) s=(s*b)%MOD;
    b=(b*b)%MOD;
    i/=2;
  }
  return s;
}
int main(){
  //clock_t start,end;
  //start=clock();

  int n; cin >>n; int sum=0;
  vector<long long>v(n);
  for(int i=0; i<n; i++) cin >>v[i];
  for(int i=0; i<60; i++){
    long long odd=0,even=0;
    for(int j=0; j<n; j++){
      if(v[j]%2) odd++;
      else even++;
      v[j]/=2;
    }
    sum=(sum+(((odd*even)%MOD)*modpow(2,i))%MOD)%MOD;
  }
  cout <<sum<<endl;

  //end=clock();
  //double time_taken=double(end-start)/double(CLOCKS_PER_SEC); 
  //cout <<"Time taken: "<<fixed<<setprecision(5);
  //cout <<time_taken<<"s/"<<time_taken*1000<<"ms"<<endl;
return 0;}