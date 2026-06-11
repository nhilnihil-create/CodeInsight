#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  int mat[s][2];
  bool f = false;
  for(int i = 0;i<s;i++){
  	cin>>mat[i][0]>>mat[i][1];    
  }
  for(int i = 0;i<s-2;i++){
  	if(mat[i][0]==mat[i][1]){
    	if(mat[i+1][0]==mat[i+1][1]){
        	if(mat[i+2][0]==mat[i+2][1]) {f = true;break;}
        }
    }
  }
  if(f) cout<<"Yes";
  else cout<<"No";
  return 0;
  
}