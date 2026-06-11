#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;

int main(){
  int n;
  ll ans=0;
  cin>>n;
  vector<vector<int>> vec(9,vector<int>(9));
  for(int i=1;i<=n;i++){
    string s=to_string(i);
    int a=s[0]-'0';
    int b=i%10;
    if(a==0||b==0)continue;
    a--;b--;
    vec[a][b]++;
  }
  rep(i,9){
    rep(j,9){
      ans+=vec[i][j]*vec[j][i];
    }
  }
  cout<<ans<<endl;
}