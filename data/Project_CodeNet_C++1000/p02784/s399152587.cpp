#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;


int main(){
  int h,n;
  cin>>h>>n;
  int tot=0;

  rep(i,n){
    int a;
    cin>>a;
    tot+=a;
  }

  if(tot>=h){
    cout<<"Yes"<<endl;
    
  }else{
    cout<<"No"<<endl;
  }

}
