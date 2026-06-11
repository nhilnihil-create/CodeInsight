#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  ll x;
  cin >> x;
  ll a = 100, count = 0; 
  
  while(a < x){
    a += a / 100;
    count++;
  }
  
  cout << count << endl;
}