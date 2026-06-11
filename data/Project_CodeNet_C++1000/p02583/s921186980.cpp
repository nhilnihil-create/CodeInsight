#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin >> N;
 int x[N];
 int count;
 for(int i=0;i<N;i++){
    cin >> x[i];    
 }
  
if(N>=3){
  int count =0;
for(int i=0;i<N;i++){
for(int j=i+1;j<N;j++){ 
for(int k=j+1;k<N;k++) {
  if(x[i]>abs(x[j]-x[k]) && x[i]<x[j]+x[k] && x[i]!=x[j] && x[j]!=x[k] && x[k]!=x[i]) count++;
  }  
  }
}
  cout << count << endl;
}
  else cout << 0 << endl;
}