#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k; cin >> n >> k;
  if(n < k)
    cout << min(n,abs(n - k));
  else{
    n = n % k;
    cout << min(abs(n),abs(n-k));
  }
}
