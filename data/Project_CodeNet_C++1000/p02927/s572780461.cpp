#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int M, D;
  cin >> M >> D;
  int ans = 0;
  auto judge = [](int m, int d){
    int d1 = d%10;
    int d10 = d/10;
    return d1>=2 && d10>=2 && d1*d10==m;
  };
  for(int i=1; i<=M; i++){
    for(int j=1; j<=D; j++){
      if(judge(i, j)) ans++;
    }
  }
  cout << ans << endl;
}