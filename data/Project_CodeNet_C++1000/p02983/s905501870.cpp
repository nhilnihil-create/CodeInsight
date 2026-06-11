#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){

  ll l,r;
  cin >> l >> r;

  ll min=2019;
  for(ll i=l;i<r;i++){
    if(i%2019==0){
      min=0;
      break;
    }

    for(ll j=i+1;j<=r;j++){
      if(j%2019==0){
        min=0;
        break;
      }

      ll remainder=(i*j)%2019;
      if(min>remainder){
        min=remainder;
      }
    }

    if(min==0){
      break;
    }
  }
cout << min << endl;

  }