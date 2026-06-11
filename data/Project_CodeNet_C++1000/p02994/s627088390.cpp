#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  int n,l;
  cin >> n >> l;
  ll total=0;
  rep(i,n){
    total+=i+l;
  }
  //cout << total << endl;
  
  if(l<=0 && l>-n) cout << total << endl;
  else if(l <= -n) cout << total - (n-1+l) << endl;
  else cout << total - l << endl;
  
}