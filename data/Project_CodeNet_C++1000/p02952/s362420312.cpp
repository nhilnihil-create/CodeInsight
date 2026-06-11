#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  if(n<=9){
    cout << n << endl;
  }
  else if(n<=99){
    cout << 9 << endl;
  }
  else if(n<=999){
    cout << 9+(n-99) << endl;
  }
  else if(n<=9999){
    cout << 909 << endl;
  }
  else if(n<=99999){
    cout << 909 +(n-9999) << endl;
  }
  else{
    cout << 90909 << endl;
  }

}