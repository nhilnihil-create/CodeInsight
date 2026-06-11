#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  int n,k;
  cin >> n >> k;
  int price[n];
  for(int i=0;i<n;i++){
    cin >> price[i];
  }
  sort(price,price + n);
  int sum=0;
  for(int i=0;i<k;i++){
    sum += price[i];
  }
  cout << sum << endl;
  return 0;
}