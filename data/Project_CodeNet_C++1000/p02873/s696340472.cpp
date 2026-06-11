#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int n = s.size()+1;

  vector<int> right(n,0);
  vector<int> left(n,0);

  int count=0;
  rep(i,n-1){
    if(s.at(i)=='<')count++;
    else count=0;
    right.at(i+1)=count;
  }
  rep(i,n-1){
    int j=n-i-2;
    if(s.at(j)=='>')count++;
    else count=0;
    left.at(j)=count;
  }

  //rep(i,n)cout<<left.at(i)<<" ";
  ll ans=0;
  rep(i,n) ans+=max(left.at(i), right.at(i));
  cout << ans;
}