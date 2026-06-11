#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
long double ep[1001];
int p[200001];
long double wa[200001];

int main() {
  int n,k;
  cin >> n >> k;
  cout << fixed << setprecision(10) ;
  ep[0] = 0;
  for(int i = 1;i <n+1;i++){
    cin >> p[i];
  }
  
  for(int i = 1;i < 1001;i++){
    ep[i] = ep[i-1] + i;
     //cout << ep[i] /i << endl;
  }
  wa[0] = 0;
  for(int i = 1;i < n+1;i++){
    wa[i] = (ep[p[i]])/p[i] + wa[i-1];
    //cout << ep[p[i]] << " " << p[i] <<" " << (ep[p[i]])/p[i] << endl;
    //cout << wa[i] << endl;
  }
  long double res = 0;
  for(int i = k;i < n+1;i++){
    res = max(res,wa[i] - wa[i-k])  ;
  }
  cout << res;
  
}