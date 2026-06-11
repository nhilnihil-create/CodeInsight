#include <iostream>
#include <math.h>
using namespace std;
int B,C; int N; int A[10];
bool dfs(int i){
  if(i==10) return true;
  if(A[i]>max(B,C)){
    if(B>C){B=A[i];}else{C=A[i];} dfs(i+1);
  }else if(A[i]<max(B,C)&&A[i]>min(B,C)){
    if(B>C){C=A[i];}else{B=A[i];} dfs(i+1);
  }else{
    return false;
  }
 }
void solve(){
  B=0; C=0;
  for(int i=0; i<10; i++){
      cin>>A[i];
    }
  if(dfs(0)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
    }
  }
int main() {
  cin>>N;
  for(int i=0; i<N; i++){
  solve();
  }
}