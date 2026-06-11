#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<29;
int main(){
  
  //入力
  int H; int N;
  cin >> H >> N;
  int A[N]; int B[N];
  for(int i=0;i<N;i++) cin >> A[i] >> B[i];
  
  int DP[H+1]; //min{-i~に必要な魔力}
  DP[0]=0;
  for(int i=1;i<=H;i++){
    int minA=INF;
    for(int j=0;j<N;j++){
      if(i>A[j]){
        minA=min(minA,DP[i-A[j]]+B[j]);
      }
      else{
        minA=min(minA,DP[0]+B[j]);
      }
    }
    DP[i]=minA;
  }
  
  cout << DP[H] << endl;
  
}
