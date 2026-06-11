#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll s;
  cin >> s;

  ll x[3];
  ll y[3];
  for(int i = 0; i < 3; i++){
    x[i] = 0;
    y[i] = 0;
  }

  if(s <= 1000000000){
    x[1] = s;
    y[1] = 0;
    x[2] = 0;
    y[2] = 1;
  }else{
    x[1] = 1000000000;
    y[1] = 1;
    x[2] = (x[1] - s % x[1]) % x[1];
    y[2] = (s + x[2]) / x[1];
  }

  for(int i = 0; i < 2; i++){
    cout << x[i] << " " << y[i] << " ";
  }
  cout << x[2] << " " << y[2] << endl;
}