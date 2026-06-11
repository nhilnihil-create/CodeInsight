#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  vector<int>a(3);
  rep(i,3){
    cin >> a.at(i);
  }
  int l,m,n ;
  l=a.at(0);
  m=a.at(1);
  n=a.at(2);
  a.at(0)=n;
  a.at(1)=l;
  a.at(2)=m;
  
  rep(j,3){ 
   cout << a.at(j) << endl;
  }
  
  

}
 