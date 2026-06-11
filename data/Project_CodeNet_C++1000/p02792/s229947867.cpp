#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n; cin>>n;
  vector<vector<int>> combi_Digit(10,vector<int>(10,0));
  int ans=0;
  for(int i=1; i<=n; i++) {
    // 最小桁
    int min=i%10;
    int max=i;
    while(max>9) max/=10;
    combi_Digit[max][min]++;
  }
  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) {
      if(i!=j) ans+=combi_Digit[i][j]*combi_Digit[j][i];
      else ans+=combi_Digit[i][j]*(combi_Digit[j][i]-1)+combi_Digit[i][j];
    }
  }
  cout << ans << endl;
}
