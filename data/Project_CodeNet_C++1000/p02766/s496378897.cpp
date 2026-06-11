#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int n, k;
  cin >> n >> k;
  
  int digit = 1;
  while(n / k != 0){
    digit++;
    n /= k;
  }
  
  cout << digit << endl;
}