#include <iostream>
using namespace std;
 
int b[10];
  
bool dfs(int i,int j,int k){
  if(k==10)
    return true;
  if(i<b[k]){
    if(dfs(b[k],j,k+1))return true; 
  }
  if(j<b[k]){
    if(dfs(i,b[k],k+1))return true;
  }
  return false;
}
 
int main(){
  int a;
  cin >> a;
  while(a>0){
    for(int i=0;i<10;i++){
      cin >> b[i];
    }
    int p=dfs(0,0,0);
    if(p!=0)
      cout << "YES" << endl;
    else
      cout << "NO" <<endl;
    a--;
  }
  return 0;
}