#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n; cin >> n;
    vector<char> s(2*n); 
    vector<int> k(2*n);
    int j = 0;
    for(int i=0;i<2*n;i++){
        cin >> s[i];
        if((i % 2 == 1 && s[i] == 'B') || (i % 2 == 0 && s[i] == 'W')){
            k[j] = i - 2*j;
            j++;
        }
    }
  if( j != n ) cout  << 0;
  else{
    ll ans = 1;
    for(int i=0;i<j;i++){
        ans *= k[i];
        ans %= MOD;
    }
    for(int i=1;i<=n;i++){
      ans *= i;
      ans %= MOD;
    }
  cout << ans % MOD;
  }
    return 0;
}

