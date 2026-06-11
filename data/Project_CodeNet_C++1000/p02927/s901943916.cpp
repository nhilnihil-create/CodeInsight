#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 210000;
const ll MOD = 1000000007;
int main(){
  int m,d;
  cin>>m>>d ;
  int ans=0;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=d;j++){
      if(j/10>=2&&j%10>=2&&(j/10)*(j%10)==i)ans++;
    }
  }
  cout<< ans<<endl;
}
