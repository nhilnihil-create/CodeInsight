#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll K,count=1;
  cin>>K;
  ll mod=7%K;
  if(K%2==0||K%5==0){
    cout<<-1<<endl;
    return 0;
  }
  while(mod>0){
    mod=(mod*10+7)%K;
    count++;
  }
  cout<<count<<endl;
}