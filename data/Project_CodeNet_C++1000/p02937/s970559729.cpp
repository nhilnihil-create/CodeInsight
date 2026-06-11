#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

string s,t;

bool isOK(int mid, int num, vector<int> &vec){
  if(vec[mid]>num) return true;
  else return false;
}

int nibutan(int &num, vector<int> &vec){
  int ng=-1, ok=vec.size();
  while(ok-ng>1){
    int mid=(ok+ng)/2;
    if(isOK(mid,num,vec)) ok=mid;
    else ng=mid;
  }
  int p=num;
  if(ok==vec.size()){
    num=vec[0];
    return s.size()-p+vec[0];
  }
  else{
    num=vec[ok];
    return vec[ok]-p;
  }
}

int main(){
  cin>>s>>t;
  vector<int> cn[26];
  rep(i,s.size()){
    cn[(int)(s[i]-'a')].push_back(i+1);
  }
  int tmp=0;
  ll ans=0;
  rep(i,t.size()){
    if(cn[(int)(t[i]-'a')].empty()){
      ans=-1; break;
    }
    ans+=nibutan(tmp,cn[(int)(t[i]-'a')]);
  }
  cout<<ans<<endl;
}