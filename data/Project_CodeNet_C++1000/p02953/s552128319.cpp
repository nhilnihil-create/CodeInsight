#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >>n;

  bool kanoukadouka=true;
  ll h[n];
  for(int i=0;i<n;i++)cin >>h[i];
  
  for(int i=n-2;i>=0;i--){
    if(h[i]<=h[i+1]);
    else if(h[i]==h[i+1]+1){
      h[i]=h[i+1];
    }
    else{
      kanoukadouka=false;
      break;
    }
  }

  if(kanoukadouka)cout << "Yes" << endl;
  else cout << "No" << endl;


}