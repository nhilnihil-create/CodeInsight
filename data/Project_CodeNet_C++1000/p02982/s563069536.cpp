#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D;
  cin>>N>>D;
  vector<vector<int>> A(N,vector<int>(D));
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      cin>>A[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){ 
      int res=0;
      for(int d=0;d<D;d++){
        int tmp=abs(A[i][d]-A[j][d]);
        res+=tmp*tmp;
      }
      for(int r=1;r<=res;r++){
        if(r*r==res){
          ans++;
        }
      }
      
    }
  }
  cout<<ans<<endl;
}