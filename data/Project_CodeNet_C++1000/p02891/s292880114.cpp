#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  string S;
  ll K;
  cin>>S>>K;
  ll N=S.size();
  if(N==1){
    cout<<K/2<<endl;
  }else if(N==2){
    if(S.at(0)==S.at(1)){
      cout<<K<<endl;
    }else{
      cout<<0<<endl;
    }
  }else{
    ll counter=0;
    bool flag=false;
    bool sub=true;
    int sub_counter=1;
    set<char> s;
    for(int i=0;i<N;i++){
      s.insert(S.at(i));
    }
    if(s.size()==1){
      cout<<K*N/2<<endl;
      return 0;
    }
    for(int i=1;i<N;i++){
      if(S.at(i-1)==S.at(i)&&sub){
        sub_counter++;
      }else{
        sub=false;
      }
      if(S.at(i-1)==S.at(i)&&!flag){
        counter++;
        flag=true;
      }else{
        flag=false;
      }
    }
    if(S.at(N-1)==S.at(0)&&!flag&&sub_counter%2==1){
      cout<<counter*K+(K-1)<<endl;
    }else{
      cout<<counter*K<<endl;
    }
  }
}
