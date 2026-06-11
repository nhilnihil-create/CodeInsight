#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D,answer=0,a,b=0,count=0;
  cin>>N>>D;
  vector<vector<int>> X(N,vector<int>(D));
    for (int i=0; i < N; ++i) {
  	for (int j=0; j < D; ++j) { 
      cin >> X[i][j];
	}
   }
  
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      b=0;
      for(int k=0;k<D;k++){
        a=X[i][k]-X[j][k];
        b+=a*a;
      }
  for(int k=0;k<=b;k++){
    if(k*k==b) count++;
  }
    }
  }
  cout<<count<<endl;
}
        