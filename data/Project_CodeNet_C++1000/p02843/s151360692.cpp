#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int X; cin >> X;
  int x = X%100;
  if ((x+4)/5<=X/100) cout << 1 << endl;
  else cout << 0 << endl;
  

  // cout << fixed << setprecision(6);
  return 0;
}

