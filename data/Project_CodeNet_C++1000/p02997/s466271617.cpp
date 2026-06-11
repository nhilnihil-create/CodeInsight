#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,j,l,n,k;
  cin >> n >> k;
  if((n-1)*(n-2)/2<k){
    cout << -1 << endl;
    return 0;
  }
  int x[110][110];
  for(i=0;i<n;i++){
    for(j-0;j<n;j++){
      x[i][j]=0;
    }
  }
  for(i=1;i<n;i++){
    x[0][i]=1;
  }
  k=(n-1)*(n-2)/2-k;
  cout << k+n-1 << endl;
  for(i=0;i<k;i++){
    int res=0;
    for(j=0;j<n;j++){
      for(l=j+1;l<n;l++){
        if(x[j][l]==0){
          x[j][l]=1,res=1;
          break;
        }
      }
      if(res==1){
        break;
      }
    }
  }
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(x[i][j]==1){
        cout << i+1 << ' ' << j+1 << endl;
      }
    }
  }
}