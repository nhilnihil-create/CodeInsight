#include<bits/stdc++.h>
using namespace std;

int main(){
int n,m,l,k = 0;
cin >> n >> m >> l;
long long A[n][m]{0}, B[m][l]{0},e = 0;

for(int i= 0;i < n;i++){
  for(int j= 0;j < m;j++){
    cin >> A[i][j];
  }
}
for(int i= 0;i < m;i++){
  for(int j= 0;j < l;j++){
    cin >> B[i][j];
  }
} 

for(int i= 0;i < n;i++){
  for(int j= 0;j < l;j++){
    for(int k = 0; k < m;k++){
      e += A[i][k] * B[k][j];
    }
    if(j+1 == l){
      cout << e << endl;
    }else{
      cout << e << " ";
    }
    e = 0;
  }
} 
return 0;
}
