#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);

  ll S; cin >> S;
  ll x1,x2,x3,y1,y2,y3;

  if(S==1000000000000000000){
    x1 = 0;
    x2 = 1000000000;
    x3 = 0;
    y1 = 0;
    y2 = 0;
    y3 = 1000000000;
  } else {
    x1 = 0;
    y1 = 0;
    x2 = 1; 
    y2 = 1000000000;
    
    y3 = y2 - S % y2;
    x3 = (S - S % y2) / (y2) + 1;
  }


  cout << x1 << " " << y1 << " ";
  cout << x2 << " " << y2 << " ";
  cout << x3 << " " << y3 << endl;

  cerr << abs(x3 * y2 -  x2 * y3) << endl;
}

