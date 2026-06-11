#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

#define MAX 200003
#define MOD 1000000007

int main(){
  int N,K;
  cin>>N>>K;
  if(K>(N-1)*(N-2)/2){
    cout<<-1<<endl;
  }else{
    cout<<N-1+(N-1)*(N-2)/2-K<<endl;
    for(int i=2;i<=N;i++){
      cout<<"1 "<<i<<endl;
    }
    int count=0;
    bool flag=false;
    for(int i=2;i<=N;i++){
      for(int j=i+1;j<=N;j++){
        if(count==(N-1)*(N-2)/2-K){
          flag=true;
          break;
        }
        cout<<i<<" "<<j<<endl;
        count++;
      }
      if(flag){
        break;
      }
    }
  }
}
