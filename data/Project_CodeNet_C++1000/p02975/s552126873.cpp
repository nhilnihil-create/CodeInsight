#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(), p.end());
  if(p[N-1]==0){
    cout<<"Yes"<<endl;
  }
  else if(N%3!=0){
    cout<<"No"<<endl;
  }
  else{
    int Z=0;
    int M=N/3;
    for(int i=1;i<N;i++){
      if(i==M||i==2*M){
        if(i==2*M&&p[0]==0&&p[i]==p[i-1]){
          continue;
        }
        else if(p[i]==p[i-1]){
          Z++;
          break;
        }
      }
      else{
        if(p[i]!=p[i-1]){
          Z++;
          break;
        }
      }
    }
    if(Z==0&&p[0]==(p[M]^p[M*2])){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
      
}