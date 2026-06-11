#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b;
  cin >> a >> b;
  ll n=0;
  ll c=1;
  while(c<b){
    c=c+(a-1);
    n++;
  }
  cout << n << endl;

}