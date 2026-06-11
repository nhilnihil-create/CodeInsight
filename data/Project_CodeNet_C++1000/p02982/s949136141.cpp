#include<bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10) ;
  int n,d,cnt=0;
  cin >> n >> d;
  int a[n][d];
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double w=0.0;
      for(int k=0;k<d;k++){
        w+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
      }
      if((double)sqrt(w)==(int)sqrt(w))cnt++;
    }
  }
  cout << cnt << endl;
}