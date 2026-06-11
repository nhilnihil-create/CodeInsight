#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long mod_pow(int x,int y){//x^yを返す//計算量は0(log(y))
  long long tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
int main(){
    string L;
    cin>>L;
    long long ans=0;
    int a=L.size(),count=0;
    for(int i=0;i<a;i++){
        if(i==0){
            ans=mod_pow(3,a-i-1);
            count++;
        }
        else if(L.at(i)=='1'){
            ans+=mod_pow(2,count)*mod_pow(3,a-i-1);
            ans%=MOD;
            count++;
        }
    }
    ans+=mod_pow(2,count);
    cout<<ans%MOD<<endl;
}