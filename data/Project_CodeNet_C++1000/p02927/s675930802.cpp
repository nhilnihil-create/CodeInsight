#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define INF 1000000000
#define MOD 1000000007

int main(){
  int M,D;
  cin>>M>>D;
  int ans=0;
  for(int i=1;i<=M;i++){
    for(int j=1;j<=D;j++){
      if((j%10)*(j/10)==i&&j%10>1&&(j/10)>1){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
