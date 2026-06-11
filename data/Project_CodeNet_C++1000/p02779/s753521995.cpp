#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615


int main(){
  int n; cin>>n;
  vector<int> a(n);
  set<int> check;
  rep(i,n) {
    int ai;
    cin>>ai;
    a.at(i)=ai;
    check.insert(ai);
  }
  
  if(check.size()==a.size()){
    cout<<"YES";
  } else {
    cout<<"NO";
  }
}