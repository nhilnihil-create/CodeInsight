#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vll = vector<long long>;

int main(){
  ll a, b, c;
  cin >> a >> b >> c;

  ll k = c - a - b;
  ll p = 4*a * b;
  ll q = k * k;

  if(k < 0){
    cout << "No" << endl;
  }
  else{
    if(p < q){
      cout << "Yes" << endl;
    }
    else{
       cout << "No" << endl;
    }
  }
}
