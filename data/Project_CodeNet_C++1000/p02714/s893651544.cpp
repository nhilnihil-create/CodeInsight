#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  ll rn=0,gn=0,bn=0;
  rep(i,n){
    if(s[i]=='R'){
      a[i]=0;
      rn++;
    }else if(s[i]=='G'){
      a[i]=2;
      gn++;
    }else{
      a[i]=3;
      bn++;
    }
  }
  
  ll miss=0;
  rep(i,n){
    for(int j=i+1;2*j-i<n;j++){
      if(a[i]+a[j]+a[2*j-i]==5){
        miss++;
      }
    }
  }
  cout << rn*gn*bn-miss;
  return 0;
}