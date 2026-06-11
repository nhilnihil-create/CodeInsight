#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  long long mod=1e9+7, ans=0;
  string l;
  cin >> l;
  if(l.size()==1){
    cout << 1+2*(l[0]-'0') << endl;
    return 0;
  }
  long long expo3[l.size()+3];
  for(size_t i=l.size()-1;i>0;i--){
    if(i==l.size()-1){
      expo3[i]=3;
      ans+=expo3[i];
    }else{
      expo3[i]=expo3[i+1]*3ll;
      expo3[i]%=mod;
      ans+=expo3[i+1]*2;
    }
    ans%=mod;
  }
  long long tmp=2;
  for(size_t i=1;i<l.size();i++){
    if(l[i]=='1'){
      if(i!=l.size()-1){
        ans+=tmp*expo3[i+1];
        ans%=mod;
      }else{
        ans+=tmp*1ll;
        ans%=mod;
      }
      tmp*=2;
    }else{
      tmp*=1;
    }
    tmp%=mod;
  }
  cout << (ans+tmp)%mod << endl;
  return 0;
}