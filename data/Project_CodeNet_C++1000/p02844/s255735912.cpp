#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

ll digitcal(ll x){
  ll n=0;
  while(x>0){
    x/=10;
    n++;
  }
  return n;
}

int main() {
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(char i='0';i<='9';i=(char)(((int)(i-'0')+1)+'0')){
    for(char j='0';j<='9';j=(char)(((int)(j-'0')+1)+'0')){
      for(char k='0';k<='9';k=(char)(((int)(k-'0')+1)+'0')){
        string temp="";
        temp+=i;temp+=j;temp+=k;
        //cout<<temp<<endl;
        int now=0;
        for(int l=0;l<n;l++){
          if(s[l]==temp[now]){
            now++;
          }
          //cout<<now<<endl;
          if(now==3) break;
        }
        //cout<<now<<endl;
        if(now==3) ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
