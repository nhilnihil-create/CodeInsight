#include<iostream>
using namespace std;
int main(){
  int n,m;
  int x[100][100]={{}};
  int y[100]={};
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> x[i][j];
    }
  }
  for(int j=0;j<m;j++){
       cin >> y[j];
  }
  for(int i=0;i<n;i++){
    int z=0;
    for(int j=0;j<m;j++) z+=x[i][j]*y[j];
    cout << z << endl;		       
  }
  
  return 0;
}
