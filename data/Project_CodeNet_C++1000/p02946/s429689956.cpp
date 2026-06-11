#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll k,x;
  cin >> k >> x;

  for(int i=x-k+1;i<x+k;i++){
    if(i>=-1000000 && i<=1000000)cout << i <<" ";
  }

}