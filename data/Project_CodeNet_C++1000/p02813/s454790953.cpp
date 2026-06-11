#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> p(n),q(n),r(n);
  rep(i,n){
    cin >> p.at(i);
  }
  rep(i,n){
    cin >> q.at(i);
  }
  rep(i,n){
    r.at(i)=i+1;
  }
  int ans=0,x=0,y=0,ct=1;
  do{
    bool is=true,no=true;
    int i=0,j=0;
    for(int a : r){
      if(p.at(i)!=a){
        is=false;
      }
      i++;
    }
    if(is){
      x=ct;
    }
    for(int a : r){
      if(q.at(j)!=a){
        no=false;
      }
      j++;
    }
    if(no){
      y=ct;
    }
    ct++;
  }while (next_permutation(r.begin(),r.end()));
  cout << abs(x-y);
}
  
    
  