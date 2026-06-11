#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  vector<int> color(3,0);
  ll ans=3;
  color.at(0)++;
  bool flag2=true;
  for(int i=1;i<N;i++){
    if(color.at(0)==color.at(1)&&color.at(1)==color.at(2)){
      if(A.at(i)!=color.at(0)){
        flag2=false;
        break;
      }
      color.at(0)++;
      ans*=3;
    }else if(color.at(0)==color.at(1)){
      if(A.at(i)==color.at(0)){
        color.at(0)++;
        ans*=2;
      }else if(A.at(i)==color.at(2)){
        color.at(2)++;
      }else{
        flag2=false;
        break;
      }
    }else if(color.at(1)==color.at(2)){
      if(A.at(i)==color.at(0)){
        color.at(0)++;
      }else if(A.at(i)==color.at(1)){
        color.at(1)++;
        ans*=2;
      }else{
        flag2=false;
        break;
      }
    }else{
      if(A.at(i)==color.at(0)){
        color.at(0)++;
      }else if(A.at(i)==color.at(1)){
        color.at(1)++;
      }else if(A.at(i)==color.at(2)){
        color.at(2)++;
      }else{
        flag2=false;
        break;
      }
    }
    ans%=MOD;
  }
  if(flag2&&A.at(0)==0){
    cout<<ans<<endl;
  }else{
    cout<<0<<endl;
  }
}
