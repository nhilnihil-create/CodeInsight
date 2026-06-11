#include<bits/stdc++.h>
#define rep(i,x) for(int i = 0; i<x; i++)

typedef long long ll;
using namespace std;

int main(){
  int X;
  cin>>X;

  int counter = X/100;
  int mo = X%100;

  int now = 0;

  for(int i = 5; i > 0; i--){
    now += mo/i;
    mo = mo%i;
  }
  if(counter >= now) cout<<1;
  else cout<<0;
}
