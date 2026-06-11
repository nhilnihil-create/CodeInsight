#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, k, s;
  cin >> n >> k >> s;
  
  if (s == 1000000000){
    for (int i = 0; i < n; i++){
      if (i < k){
        cout << s;
      }
      else 
        cout << 1;

      if (i == n - 1)
        cout << endl;
      else
        cout << " ";
    }
  }
  else {
    for (int i = 0; i < n; i++){
      if (i < k){
        cout << s;
      }
      else 
        cout << s + 1;

      if (i == n - 1)
        cout << endl;
      else
        cout << " ";
    }
  }

  return 0;
}
