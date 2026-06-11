#include<bits/stdc++.h> 
using namespace std;
 
int main(){
 
  long long int N,D;
  long long count=0;
  cin >> N>>D;
  long double X[N][D];
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
    cin >> X[i][j];
    }
  }
 for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      long double T=0;
      for(int k=0;k<D;k++){
          T+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      }
      T=sqrt(T);
      if(abs(T-floor(T))<0.00001){
          count++;
    }
  }
 }
  cout << count;
 return 0;
}