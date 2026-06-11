#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int gcd(int x, int y) {
  if(y == 0) {
    return x;
  } else{
    return gcd(y, x % y);
  }
}

int gcd2(int x, int y, int z){
  int a = gcd(x, y);
  if(z == 0) {
    return a;
  } else{
    return gcd(z, a % z);
  }
}
  
int main(){
  int k, sum = 0;
  cin >> k;
  k++;
  rep(i, 1, k){
    rep(j, 1, k){
      rep(l, 1, k){
        sum += gcd2(i, j, l);
      }
    }
  }
  
  cout << sum << "\n";
}
  
  
  
  
  
  
  
  
  
  