#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,j,k,n,d,a[15][15];
  vector<int> x(100010,0);
  cin >> n >> d;
  for(i=0;i<n;i++){
    for(j=0;j<d;j++){
      scanf("%d ",&a[i][j]);
    }
  }
  int ans=0;
  for(i=0;i*i<=100000;i++){
    x[i*i]=1;
  }
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      int len=0;
      for(k=0;k<d;k++){
        len+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
      }
      if(x[len]==1){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}