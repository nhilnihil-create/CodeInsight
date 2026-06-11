#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long long> S(N);
  for(int i=0; i<N; i++){
    cin>>S.at(i);
  }
  if(N<=2)
    cout<<0<<endl;
  else{
    sort(S.begin(),S.end());
    int K=0;
    int Ans=0;
    for(int i=0; i<N-2; i++){
      for(int j=i+1; j<N-1; j++){
        for(int l=j+1;l<N; l++){
          if(S.at(i)!=S.at(j)&&S.at(j)!=S.at(l)){
            K++;
          }
            if(S.at(i)+S.at(j)>S.at(l)){
              K++;
            }
          if(K==2){
            Ans++;
          }
          K=0;
        }
      }
    }
    cout<<Ans<<endl;
            
  }
}
