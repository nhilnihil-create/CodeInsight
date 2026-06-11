#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  int N,M;
  string S;
  cin>>N>>M>>S;
  vector<int> a;
  int i=N;
  bool flag=true;
  while(i>0){
    if(i<=M){
      a.push_back(i);
      i=0;
    }else{
      bool sub=false;
      for(int j=M;j>0;j--){
        if(S.at(i-j)=='0'){
          a.push_back(j);
          i-=j;
          sub=true;
          break;
        }
      }
      if(!sub){
        flag=false;
        break;
      }
    }
  }
  if(flag){
    for(int i=a.size()-1;i>=0;i--){
      cout<<a.at(i)<<" ";
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }
}
