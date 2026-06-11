#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >> n;
  vector<int> w(n);
  for(int i=0; i<n; ++i) cin >> w[i];
  int sum1 = 0, sum2 = 0;
  int ans = 100;

  for(int i=0; i<n; ++i){
    sum1 = 0;
    sum2 = 0;
    for(int j=0; j<=i; ++j){
      sum1 += w[j];
    }
    for(int k=i+1; k<n; ++k){
      sum2 += w[k];
    }
    int dif = abs(sum1-sum2);
    ans = min(dif, ans);
  }

  cout << ans << endl;


}