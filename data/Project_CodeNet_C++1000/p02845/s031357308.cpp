#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>count(3);
  long long ans=1;
  for(int i=0;i<N;i++){
    int a;cin>>a;
    bool b=false;
    int p=0;
    for(int j=0;j<3;j++){
      if(count[j]==a){
        p++;
        if(!b){
          count[j]++;
          b=true;
        }
      }
    }
    ans*=p;
    ans%=int(1e9+7);
  }
  cout<<ans<<endl;
}