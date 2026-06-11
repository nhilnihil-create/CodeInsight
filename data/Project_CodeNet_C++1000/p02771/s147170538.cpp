#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const int INF=1e9;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  
  if(a==b || b==c || c==a){
    if(a==b && b==c){
      cout<<"No"<<endl;
      return 0;
    }else{
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;
}