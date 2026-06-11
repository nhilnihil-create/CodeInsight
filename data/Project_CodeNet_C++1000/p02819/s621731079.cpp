#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check_prime(ll n) {
  bool check = true;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) check = false;
  }
  return check;
}

int main() { 
    ll X;
    cin >> X;
    for (int i = X;;i++){
        if(check_prime(i)){
            cout << i <<endl;
            break;
        }
    } return 0;
}