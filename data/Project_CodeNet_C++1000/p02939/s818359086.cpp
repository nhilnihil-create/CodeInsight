#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int ans=0;
  int i=0;
  bool flag=true;
  while(i<N){
    if(flag){
      ans++;
      flag=false;
      i++;
    }else{
      if(S.at(i-1)!=S.at(i)){
        ans++;
        i++;
      }else{
        if(i==N-1){
          i++;
          continue;
        }
        ans++;
        flag=true;
        i+=2;
      }
    }
  }
  cout<<ans<<endl;
}
