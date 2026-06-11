#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int c=0;
  cin>>N;
  vector<long long>L(N);
  for(int i=0;i<N;i++){
  cin>>L[i];
    
  }
for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        if(L[i]!=L[j]&&L[j]!=L[k]&&L[k]!=L[i]){
if(L[i]+L[j]>L[k]&&L[k]+L[i]>L[j]&&L[j]+L[k]>L[i]){
c++;
}
        }
      }
    }
  }
  
  cout<<c<<endl;
}
