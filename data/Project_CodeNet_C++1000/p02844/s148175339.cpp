#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;
 

ll  n; string s;
ll midnum(int i,int j){
  set<int> s_mid;
  for(int k=i+1; k<j; k++){
    int i3=(int)s[k]-48;
    s_mid.insert(i3);
  }
  return s_mid.size();
}
int main() {
  cin>>n>>s;
  vector<int> v(10,0);
  vector<int> v_first, v_last;
  rep(k,n){
    int i1=(int)s[k]-48;
    if(v.at(i1)==0){
      v.at(i1)=1;
      v_first.push_back(k);
    }   
  }
  vector<int> v_(10,0);
  rep(k,n){
    int i2=(int)s[n-k-1]-48;
    if(v_.at(i2)==0){
      v_.at(i2)=1;
      v_last.push_back(n-k-1);
    }
  }
  ll count=0;
  for(int i: v_first){
    for(int j: v_last){
      if(j-i>=2){count+=midnum(i,j);}
    }
  }
  cout<<count;
}