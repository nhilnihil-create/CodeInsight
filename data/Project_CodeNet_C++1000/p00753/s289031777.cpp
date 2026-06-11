//Chebyshev's Theorem
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> prime;
int pn[123456*2+1];

int main(){
  prime.push_back(2);
  pn[2]=1;
  for(ll i=3; i<123456*2+1; i++){
    bool flag=true;
    for(ll j=0; j<prime.size() && i>=prime[j]*prime[j]; j++){
      if(i%prime[j]==0){flag=false; break;}
    }
    if(flag){prime.push_back(i); pn[i]=pn[i-1]+1;}
    else{pn[i]=pn[i-1];}
  }
  ll n;
  while(true){
    cin>>n;
    if(n==0)break;
    cout<<pn[n*2]-pn[n]<<endl;
  }
  return 0;
}