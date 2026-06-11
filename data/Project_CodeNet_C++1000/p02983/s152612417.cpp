#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll l,r;
  cin >> l >> r;
  if(r-l>673){
    cout << 0 << endl;
  }else{
    ll minmod=2018,i,j;
    for(i=l;i<r;i++){
      for(j=i+1;j<=r;j++){
        minmod=min(minmod,(i*j)%2019);
      }
    }
    cout << minmod << endl;
  }
}