#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

const int MOD = 1000000007;
long long int n, k, a[5000];

int main(){
  cin >> n >> k;
  rep(i, n){
    cin >> a[i];
  }
  long long int sum = 0;
  rep(i, n){
    long long int fw = 0, bw = 0;
    rep(j, n){
      if(j < i && a[i] < a[j]){
        fw++;
      }
      if(j > i && a[i] < a[j]){
        bw++;
      }
    }
    sum += k * fw;
    sum %= MOD;
    
    long long int tmp = 0;
    tmp = k * (k - 1);
    tmp /= 2;
    tmp %= MOD;
    tmp *= (fw + bw);
    tmp %= MOD;
    sum += tmp;
    sum%= MOD;
  }
  cout << sum << endl; 
  return 0;
}
