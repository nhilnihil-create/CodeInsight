#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
using Graph=vector<vector<int>>;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N,vector<int>(N-1));
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      cin>>A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }

  bool flag=true;
  vector<int> finish(N,0),day(N,0);
  while(1){
    bool sub=false;
    int sum=0;
    for(int i=0;i<N;i++){
      sum+=finish.at(i);
      if(finish.at(i)==N-1){
        continue;
      }
      int x=A.at(i).at(finish.at(i));
      if(A.at(x).at(finish.at(x))==i){
        sub=true;
        finish.at(i)++;
        finish.at(x)++;
        day.at(x)=max(day.at(i)+1,day.at(x)+1);
        day.at(i)=day.at(x);
        break;
      }
    }
    if(sum==N*(N-1)){
      break;
    }
    if(sub){
      continue;
    }
    flag=false;
    break;
  }
  if(flag){
    int ans=0;
    for(int i=0;i<N;i++){
      ans=max(ans,day.at(i));
    }
    cout<<ans<<endl;
  }else{
    cout<<-1<<endl;
  }

}
