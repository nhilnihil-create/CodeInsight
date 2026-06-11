#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long mod_pow(long long x,long long y){//x^yを返す//計算量は0(log(y))
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
    int a=L.size();
    int last1=a,count=0;
    for(int i=0;i<a;i++){
        if(i==0){
            ans=mod_pow(3,a-i-1);
            last1=i;
            count++;
        }
        else{
            /*
            if(L.at(i)=='1' && last1==i-1){
                last1=i;
                ans*=3;
                ans%=MOD;
            }
            */
            if(L.at(i)=='1'){
                ans+=mod_pow(2,count)*mod_pow(3,a-i-1);
                ans%=MOD;
                last1=i;
                count++;
            }
        }
        //cout<<i<<" "<<ans<<endl;
    }
    ans+=mod_pow(2,count);
    ans%=MOD;
    cout<<ans<<endl;
}