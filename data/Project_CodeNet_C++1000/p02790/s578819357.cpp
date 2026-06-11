#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int jack(int x, int y){
  int k=0;
  rep(i,y){
    
    k=10*k+1;
  }
  x=k*x  ;
  return x;
}

int main() {
  int a,b;
  cin >> a >> b;
  if(a<b){
    int k=jack(a,b);
    cout << k << endl;
  }
  else{
    int h=jack(b,a);
    cout << h << endl;
  }
  

  return 0;

}

