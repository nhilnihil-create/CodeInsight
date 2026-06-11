#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  int n;
  vector<int> x(2*123456 + 1, 0);
  for(int i = 2; i < sqrt(x.size()); i++){
    if(x[i] == 0){
      for(int j = 2*i; j <= x.size(); j += i){
        x[j] = 1;
      }
    }
  }
  while(cin >> n, n){
     int ans = 0;
     for(int i = n + 1; i <= 2*n; i++){
      if(x[i] == 0)ans++;
     }
     cout << ans << endl;
  }
}