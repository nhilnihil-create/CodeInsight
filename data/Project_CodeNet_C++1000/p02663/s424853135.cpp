#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);


  int h1,m1,h2,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int hun = ((h2+24)*60 + m2 - ((h1*60)+m1))%(24*60);
  cout << hun - k << endl;
  
  
  return 0;
    

}
