#define PI 3.14159265359
#define INF 2000000000
#define MAX 500000
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;


void MCM(int n,int p[]){
  int m[120][120];
  for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) m[i][j]=(1<<30);
  
  for(int i=1;i<=n;i++) m[i][i]=0;
  
  for(int l=2;l<=n;l++){
      for(int i=1;i<=n-l+1;i++){
          int j=i-1+l;
          for(int k=i;k<j;k++){
              m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
          }
      }
  }
  
   cout<<m[1][n]<<endl;
}

int main(){
   int p[120];
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
     cin>>p[i-1]>>p[i]; 
   }
 MCM(n,p);
}