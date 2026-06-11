#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
using pp=pair<int,pair<int,int>>;
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N,K;
  cin>>N>>K;
  if(K==1){
    cout<<0<<endl;
  }else if(N==K){
    cout<<0<<endl;
  }else{
    cout<<N-K<<endl;
  }
}
