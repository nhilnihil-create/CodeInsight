#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
long long save[2001][2001];
int main(){
  prep();
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i=0; i<n; i++){
      cin >> a[i];
  }
  for (int i=0; i<m; i++){
      cin >> b[i];
  }
  for (int i=0; i<n; i++){
      save[i][m] = 1;
  }
  for (int i=0; i<m; i++){
      save[n][i] = 1;
  }
  save[n][m] = 1;
  for (int i=n-1; i>=0; i--){
      for (int j=m-1; j>=0; j--){
          long long val = mymod(-save[i+1][j+1]+save[i+1][j]+save[i][j+1]);
          if (a[i] == b[j]){
              save[i][j] = mymod(save[i+1][j+1]+val);
          }else{
              save[i][j] = val;
              
          }
         // cout << i << " " << j << " " << save[i][j] << endl;
      }
  }
  
  cout <<save[0][0];
  return 0; 
}