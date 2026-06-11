#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll n,k,s;
  cin >> n >> k >> s;

  ll INF = pow(10,9);
  if(s==INF) INF--;
  
  rep(i,n){
    if(i<k) cout<<s<<" ";
    else cout<<INF<<" ";
  }
}