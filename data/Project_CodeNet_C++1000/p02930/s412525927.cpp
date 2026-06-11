#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;

int ans[501][501];

int main(){
  cin>>N;

  for(int i=1;i<=N;i++){
      for(int j=i+1;j<=N;j++){
          for(int k=0;k<30;k++){
              if((i&(1<<k))!=(j&(1<<k))){
                  ans[i][j]=k+1;
                  break;
              }
          }
      }
  }

  for(int i=1;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
