#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;i++)

int zeta(int a,int b){
  if(a>=b) return a-b;
  else return b-a;
}

int main(){
  string t;cin>>t;
  int len=t.size();
  
  for(int i=0;i<len;i++){
    if(t.at(i)=='?'){
      t.at(i)='D';
    }
  }
  cout<<t<<endl;
  return 0;
}






