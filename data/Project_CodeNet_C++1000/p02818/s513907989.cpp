#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, k;
  cin >> a >> b >> k;

  if(a>=k)a-=k;
  else if(a+b>k){
    b-=k-a;
    a=0;
  }
  else{
    a=0;
    b=0;
  }

  cout << a << " " << b << endl;

  return 0;
}