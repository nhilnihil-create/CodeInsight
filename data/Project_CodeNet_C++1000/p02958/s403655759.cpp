#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  
  vector<int> p(n);
  rep(i,n) cin >> p.at(i);

  int count = 0;
  rep(i,n){
    if(p.at(i)!=i+1) count++;
  }

  if(count==0||count==2)cout << "YES";
  else cout << "NO";
}