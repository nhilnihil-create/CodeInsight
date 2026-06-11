#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(ll i=0;i<ll(n);i++)

bool magic(int a, int b, int c, int k){
  
  int d =0;
while(a >= b){
  b *= 2;
  d++;
}
  while(b >= c){
    c *=2;
    d++;
  }
  
 return d<=k?true:false;
  
}

int main(){
 int a=0, b=0, c=0, k=0;
  
  cin >> a >> b >> c;
  cin >> k;
  string e = magic(a, b, c, k)?"Yes":"No";
    cout << e << endl;

  return 0;
  
}
