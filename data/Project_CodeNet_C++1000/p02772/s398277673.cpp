#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const int INF=1e9;

int n;

int main(){
  cin>>n;
  bool judge=true;
  
  rep(i,n){
    int a;
    cin>>a;
    if(a%2==0){
      if(a%3!=0 && a%5!=0){
        judge=false;
        cout<<"DENIED"<<endl;
        return 0;
      }
    }
  }

  cout<<"APPROVED"<<endl;
  return 0;
}