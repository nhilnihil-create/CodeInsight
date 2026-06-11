#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
 vector<int> S(N);
  int checker=0;
  for(int i=0; i<N;i++){
    cin>>S.at(i);
    if(S.at(i)==1)
      checker++;
  }
  if(checker==0)
    cout<<-1<<endl;
  else{
   int Ans=0;
    int L=1;
    for(int i=0; i<N; i++){
      if(S.at(i)!=L)
        Ans++;
      else {
        L++;
      }
    }
    cout<<Ans<<endl;
  }
      
}
