#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int rsum[N+1][N];
int in[N][N];

void precalc(int n){
  for(int j=0;j<n;j++){
    rsum[0][j] = 0;
    for(int i=0;i<n;i++){
      rsum[i+1][j] = rsum[i][j] + in[i][j];
    }
  }
}

int maximumSum1D(int n,int *a){
  int ret = a[0],cur = a[0];
  for(int i=1;i<n;i++){
    if (cur < 0){
      cur = a[i];
    }else {
      cur = cur + a[i];
    }
    ret = max(ret,cur);
  }
  return ret;
}

int solve(int n){
  int ret = 0;
  int a[n];
  for(int i=0;i<n;i++){
    for(int k=i;k<n;k++){
      for(int j=0;j<n;j++){
	a[j] = rsum[k+1][j] - rsum[i][j];
      }
      ret = max(ret,maximumSum1D(n,a));
    }
  }
  return ret;
}

main(){
  int n;
  while(cin>>n && n){
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    cout << maximumSum1D(n,a) << endl;
  }
}