#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin>>H.at(i);
  }
  for(int i=N-1; i>0; i--){
    if(H[i]<H[i-1]){
      if(H[i]>=H[i-1]-1){
        H[i-1]--;
        continue;
      }
      else{
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
}